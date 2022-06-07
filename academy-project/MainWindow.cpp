#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Worker.h"
#include "ConstStringDefinition.h"


// =================================== MAIN WINDOW ==========================================
MainWindow::MainWindow(QWidget *parent, GenericWorker *genericWorker)
    : QMainWindow(parent)
    ,   ui(new Ui::MainWindow)
{
    qDebug() << "MainWindow::MainWindow Constructor -> START";
    ui->setupUi(this);
    this->worker = genericWorker;
    QObject::connect(ui->logTableView, SIGNAL(customContextMenuRequested(QPoint)), SLOT(customMenuRequested()));

    ui->logTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->logTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->logTableView->setModel(worker->getModel());

    // Update delle Label e delle Combo Box
    updateApprochInfo(getApproch());
    updateTypeComboBox(getApproch());
    updateTypeInfo(getType());

    qDebug() << "MainWindow::MainWindow Constructor -> STOP";
}

MainWindow::~MainWindow()
{
    delete ui;
}
// ===========================================================================================


// ====================== GESTIONE DELLE PROGRESS BAR ==================================
void MainWindow::slotUpdateProgressBar(int perc)
{
    qDebug() << "MainWindow::slotUpdateProgressBar -> START";

    GenericTask * task = dynamic_cast<GenericTask*>(sender());
    QString taskProgressBarObjecUniqueName = this->worker->findValueInProgressBarThreadMap(task->getID());
    QProgressBar* temp = ui->scrollAreaWidgetProgressBar->findChild<QProgressBar*>(taskProgressBarObjecUniqueName);
    temp->setValue(perc);
    qDebug() << "MainWindow::slotUpdateProgressBar -> Setting " << taskProgressBarObjecUniqueName << " to " << perc;
    if(perc == 100)
    {
        qDebug() << "MainWindow::slotUpdateProgressBar -> Setting " << taskProgressBarObjecUniqueName << " to COMPLETED";
        this->worker->updateItemStateOnModel(taskProgressBarObjecUniqueName, EnumsType::ThreadState::Completed);
    }

    qDebug() << "MainWindow::slotUpdateProgressBar -> STOP";
}


// ====================================== GESTIONE BUTTONS =======================================
void MainWindow::on_pushButtonApply_clicked()
{
    qDebug() << "MainWindow::on_pushButtonApply_clicked -> START";

    EnumsType::PossibleApproch approch = this->getApproch();
    EnumsType::PossibleType type = this->getType();
    EnumsType::Difficulty diff = this-> getDifficulty();

    qDebug() << "MainWindow::on_pushButtonApply_clicked -> Approch:    "    << EnumsType::toString(approch) << "\n"
                "MainWindow::on_pushButtonApply_clicked -> Type:       "    << EnumsType::toString(type)    << "\n"
                "MainWindow::on_pushButtonApply_clicked -> Difficulty: "    << EnumsType::toString(diff)    << "\n";

    GenericTask* task = this->worker->handleMessage(approch, type, diff);
    int newTaskID = task->getID();
    QObject::connect(task, &GenericTask::updateProgressBar, this, &MainWindow::slotUpdateProgressBar);

    if (newTaskID == 0) {
        throw std::invalid_argument( "Worker::handleMessage didn't generate a task" );
    }
    QString progressBarObjectUniqueName = addProgressBarToFrame(newTaskID);
    this->worker->addNewItemOnModel(progressBarObjectUniqueName, approch, type, diff, EnumsType::ThreadState::Started);

    this->worker->sendSignalCalculate();

    qDebug() << "MainWindow::on_pushButtonApply_clicked -> STOP\n";
}

void MainWindow::on_pushButtonAppendThread_clicked()
{
    qDebug() << "MainWindow::on_pushButtonAppendThread_clicked -> START";

    EnumsType::PossibleApproch approch = this->getApproch();
    EnumsType::PossibleType type = this->getType();
    EnumsType::Difficulty diff = this-> getDifficulty();

    GenericTask* task = this->worker->handleMessage(approch, type, diff);
    int newTaskID = task->getID();

    QObject::connect(task, &GenericTask::updateProgressBar, this, &MainWindow::slotUpdateProgressBar);

    if (newTaskID == 0) {
        // TO-DO
        // Bisogna gestire questa eccezione, anche se non viene mai creata
        throw std::invalid_argument( "Worker::handleMessage didn't generate a task" );
    }
    QString progressBarObjectUniqueName = addProgressBarToFrame(newTaskID);
    this->worker->addNewItemOnModel(progressBarObjectUniqueName, approch, type, diff, EnumsType::ThreadState::Started);

    qDebug() << "MainWindow::on_pushButtonAppendThread_clicked -> STOP\n";
}

void MainWindow::on_pushButtonAppendThreadStart_clicked()
{
    qDebug() << "MainWindow::on_pushButtonAppendThreadStart_clicked -> START";

    this->worker->sendSignalCalculate();

    qDebug() << "MainWindow::on_pushButtonAppendThreadStart_clicked -> STOP\n";
}
// ===============================================================================================


// ====================== GESTIONE DELLA CREAZIONE DELLA PROGRESS BAR ======================
QString MainWindow::addProgressBarToFrame(int taskID)
{
    qDebug() << "MainWindow::addProgressBarToFrame -> START";

    // Dichiarazione delle variabili
    QFrame*         progressBarHorFrame = new QFrame();
    QProgressBar*   progressBarObject   = new QProgressBar();
    QLabel*         progressBarLabel    = new QLabel();
    QHBoxLayout*    horizLayout         = new QHBoxLayout;

    // Gestione della Progress Bar
    QString progressBarObjectUniqueName   = "ProgressBar_ID_" + QString::number(taskID);
    this->worker->insertValueToProgressBarThreadMap(taskID, progressBarObjectUniqueName);
    progressBarObject->setObjectName(progressBarObjectUniqueName);
    progressBarObject->setValue(0);


    // Gestione della Label della Progress Bar
    QString progressBarLabelUniqueName   = "labelProgressBarID_" + QString::number(taskID);
    progressBarLabel->setText(progressBarObjectUniqueName + ": ");
    progressBarLabel->setObjectName(progressBarLabelUniqueName);

    //Gestione del Frame della Progress Bar
    QString progressBarFrameUniqueName   = "FrameProgressBar_ID_" + QString::number(taskID);
    progressBarHorFrame->setObjectName(progressBarFrameUniqueName);
    progressBarHorFrame->setLayout(horizLayout);
    progressBarHorFrame->layout()->addWidget(progressBarLabel);
    progressBarHorFrame->layout()->addWidget(progressBarObject);
    this->ui->scrollAreaWidgetProgressBar->layout()->addWidget(progressBarHorFrame);

    qDebug() << "MainWindow::addProgressBarToFrame -> Added new progressBarFrame:  " << progressBarFrameUniqueName;
    qDebug() << "MainWindow::addProgressBarToFrame -> Added new progressBarObject: " << progressBarObjectUniqueName;
    qDebug() << "MainWindow::addProgressBarToFrame -> Added new progressBarLabel:  " << progressBarLabelUniqueName;



    qDebug() << "MainWindow::addProgressBarToFrame -> STOP";
    return progressBarObjectUniqueName;
}


// ===================================== GESTIONE COMBO BOX =====================================
void MainWindow::on_comboBoxApproch_currentTextChanged(const QString &comboApprochCurrentText)
{
    qDebug() << "MainWindow::on_comboBoxApproch_currentTextChanged -> START";
    qDebug() << "MainWindow::on_comboBoxApproch_currentTextChanged -> comboBoxText: " << comboApprochCurrentText;

    EnumsType::PossibleApproch approch = EnumsType::PossibleApproch::None;

    if (comboApprochCurrentText == COMBO_BOX_APPROCH_SORTING)
    {
        approch = EnumsType::PossibleApproch::Sorting;
    }
    else if (comboApprochCurrentText == COMBO_BOX_APPROCH_NUMBER)
    {
        approch = EnumsType::PossibleApproch::Present;
    }
    else if (comboApprochCurrentText == COMBO_BOX_APPROCH_MISSING)
    {
        approch = EnumsType::PossibleApproch::Problem;
    }

    updateApprochInfo(approch);
    updateTypeComboBox(approch);

    qDebug() << "MainWindow::on_comboBoxApproch_currentTextChanged -> STOP";
}

void MainWindow::on_comboBoxType_currentTextChanged(const QString &type)
{
    Q_UNUSED(type);
    qDebug() << "MainWindow::on_comboBoxType_currentTextChanged -> START";

    updateTypeInfo(getType());

    qDebug() << "MainWindow::on_comboBoxType_currentTextChanged -> STOP";
}
// ===============================================================================================




// ====================== GESTIONE MENU ======================
void MainWindow::on_actionCreators_triggered()
{
    qDebug() << "Worker::on_actionCreators_triggered -> START";
    QMessageBox msgBox;
    msgBox.setObjectName("creatorsMessageBox");
    msgBox.setWindowTitle("About the creators");
    msgBox.setText(MENU_CREATORS_INFO_RICH_TEXT);
    msgBox.setTextFormat(Qt::RichText);
    msgBox.exec();
    qDebug() << "Worker::on_actionCreators_triggered -> STOP";
}

void MainWindow::customMenuRequested()
{
    QItemSelectionModel *select = ui->logTableView->selectionModel();
    for(auto id : select->selectedRows())
    {
        ui->logTableView->model()->removeRow(id.row());
    }
}
// ===========================================================



// ====================== GESTIONE DEGLI UPDATES ======================
void MainWindow::updateTypeComboBox(EnumsType::PossibleApproch approch)
{
    qDebug() << "MainWindow::updateTypeComboBox -> START";

    this->ui->comboBoxType->clear();

    QStringList list;

    if (approch == EnumsType::PossibleApproch::Sorting)
    {
        list.append(COMBO_BOX_APPROCH_TYPE_BUBBLESORT);
        list.append(COMBO_BOX_APPROCH_TYPE_QUICKSORT);
        list.append(COMBO_BOX_APPROCH_TYPE_MERGESORT);

        updateTypeInfo(EnumsType::PossibleType::BubbleSort);
    }
    else if (approch == EnumsType::PossibleApproch::Present)
    {
        list.append(COMBO_BOX_APPROCH_TYPE_NUMBERPRESENT);

        updateTypeInfo(EnumsType::PossibleType::NumberPresent);
    }
    else if (approch == EnumsType::PossibleApproch::Problem)
    {
        list.append(COMBO_BOX_APPROCH_TYPE_MISSINGNUMBER);
        updateTypeInfo(EnumsType::PossibleType::MissingNumber);
    }

    this->ui->comboBoxType->addItems(list);

    qDebug() << "MainWindow::updateTypeComboBox -> STOP";
}

void MainWindow::updateApprochInfo(EnumsType::PossibleApproch approch)
{
    qDebug() << "MainWindow::updateApprochInfo -> START";

    QString text = "Error";
    if (approch == EnumsType::PossibleApproch::Sorting)
    {
        text = COMBO_BOX_APPROCH_SORTING_INFO;
    }
    else if (approch == EnumsType::PossibleApproch::Present)
    {
        text = COMBO_BOX_APPROCH_NUMBER_INFO;
    }
    else if (approch == EnumsType::PossibleApproch::Problem)
    {
        text = COMBO_BOX_APPROCH_MISSING_INFO;
    }

    this->ui->labelApprochInfo->setText(text);

    qDebug() << "MainWindow::updateApprochInfo -> STOP";
}

void MainWindow::updateTypeInfo(EnumsType::PossibleType type)
{
    qDebug() << "MainWindow::updateTypeInfo -> START";

    QString text = "Error";
    if (type == EnumsType::PossibleType::BubbleSort)
    {
        text = COMBO_BOX_APPROCH_TYPE_BUBBLESORT_INFO;
    }
    else if (type == EnumsType::PossibleType::QuickSort)
    {
        text = COMBO_BOX_APPROCH_TYPE_QUICKSORT_INFO;
    }
    else if (type == EnumsType::PossibleType::MergeSort)
    {
        text = COMBO_BOX_APPROCH_TYPE_MERGESORT_INFO;
    }
    else if (type == EnumsType::PossibleType::NumberPresent)
    {
        text = COMBO_BOX_APPROCH_TYPE_NUMBERPRESENT_INFO;
    }
    else if (type == EnumsType::PossibleType::MissingNumber)
    {
        text = COMBO_BOX_APPROCH_TYPE_MISSINGNUMBER_INFO;
    }

    this->ui->labelTypeInfo->setText(text);

    qDebug() << "MainWindow::updateTypeInfo -> STOP";
}
// ====================================================================



// ========================== GETTER ==========================
EnumsType::PossibleApproch MainWindow::getApproch()
{

    if(ui->comboBoxApproch->currentText() == COMBO_BOX_APPROCH_SORTING)
    {
        return EnumsType::PossibleApproch::Sorting;
    }
    else if(ui->comboBoxApproch->currentText() == COMBO_BOX_APPROCH_NUMBER)
    {
        return EnumsType::PossibleApproch::Present;
    }
    else if(ui->comboBoxApproch->currentText() == COMBO_BOX_APPROCH_MISSING)
    {
        return EnumsType::PossibleApproch::Problem;
    }

    return EnumsType::PossibleApproch::None;
}

EnumsType::Difficulty MainWindow::getDifficulty()
{
    if(ui->radioButtonEasy->isChecked())
    {
        return EnumsType::Difficulty::Easy;
    }
    else if(ui->radioButtonMedium->isChecked())
    {
        return EnumsType::Difficulty::Medium;
    }
    else if(ui->radioButtonHard->isChecked())
    {
        return EnumsType::Difficulty::Hard;
    }

    return EnumsType::Difficulty::None;
}

EnumsType::PossibleType MainWindow::getType()
{
    if(ui->comboBoxType->currentText() == COMBO_BOX_APPROCH_TYPE_BUBBLESORT)
    {
        return EnumsType::PossibleType::BubbleSort;
    }
    else if(ui->comboBoxType->currentText() == COMBO_BOX_APPROCH_TYPE_QUICKSORT)
    {
        return EnumsType::PossibleType::QuickSort;
    }
    else if(ui->comboBoxType->currentText() == COMBO_BOX_APPROCH_TYPE_MERGESORT)
    {
        return EnumsType::PossibleType::MergeSort;
    }

    else if(ui->comboBoxType->currentText() == COMBO_BOX_APPROCH_TYPE_NUMBERPRESENT)
    {
        return EnumsType::PossibleType::NumberPresent;
    }

    else if(ui->comboBoxType->currentText() == COMBO_BOX_APPROCH_TYPE_MISSINGNUMBER)
    {
        return EnumsType::PossibleType::MissingNumber;
    }

    return EnumsType::PossibleType::None;
}
// ============================================================


