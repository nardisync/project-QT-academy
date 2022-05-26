#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Worker.h"
#include "ConstStringDefinition.h"

// =================================== MAIN WINDOW ==========================================
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    ,   ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    worker = new Worker(ui);

    ui->logTableView->setModel(worker->getModel());

    // Update delle Label e delle Combo Box
    updateApprochInfo(getApproch());
    updateTypeComboBox(getApproch());
    updateTypeInfo(getType());
}

MainWindow::~MainWindow()
{
    delete ui;
}
// ===========================================================================================



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

    this->worker->handleMessage(approch, type, diff);

    // TO-DO: Vogliamo lasciarlo pubblico? o implementiamo
    // un altro sistema?
    // Cosi crashiamo, ma ci permette di fare l'append
    this->worker->sendSignalCalculate();

    qDebug() << "MainWindow::on_pushButtonApply_clicked -> STOP\n";
}

void MainWindow::on_pushButtonAppendThread_clicked()
{
    qDebug() << "MainWindow::on_pushButtonAppendThread_clicked -> START";

    EnumsType::PossibleApproch approch = this->getApproch();
    EnumsType::PossibleType type = this->getType();
    EnumsType::Difficulty diff = this-> getDifficulty();

    this->worker->handleMessage(approch, type, diff);

    qDebug() << "MainWindow::on_pushButtonAppendThread_clicked -> STOP";
}

void MainWindow::on_pushButtonAppendThreadStart_clicked()
{
    qDebug() << "MainWindow::on_pushButtonAppendThreadStart_clicked -> START";

    this->worker->sendSignalCalculate();

    qDebug() << "MainWindow::on_pushButtonAppendThreadStart_clicked -> STOP";
}
// ===============================================================================================



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
    else if (comboApprochCurrentText == COMBO_BOX_APPROCH_MERGING)
    {
        approch = EnumsType::PossibleApproch::Merging;
    }
    else if (comboApprochCurrentText == COMBO_BOX_APPROCH_PROBLEM)
    {
        approch = EnumsType::PossibleApproch::Problem;
    }

    updateApprochInfo(approch);
    updateTypeComboBox(approch);

    qDebug() << "MainWindow::on_comboBoxApproch_currentTextChanged -> STOP";
}

void MainWindow::on_comboBoxType_currentTextChanged(const QString &type)
{
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
    else if (approch == EnumsType::PossibleApproch::Merging)
    {
        list.append(COMBO_BOX_APPROCH_TYPE_NORMALMERGE);

        updateTypeInfo(EnumsType::PossibleType::NormalMerging);
    }
    else if (approch == EnumsType::PossibleApproch::Problem)
    {
        list.append(COMBO_BOX_APPROCH_TYPE_NORMALPROBLEM);
        updateTypeInfo(EnumsType::PossibleType::NormalProblem);
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
    else if (approch == EnumsType::PossibleApproch::Merging)
    {
        text = COMBO_BOX_APPROCH_MERGING_INFO;
    }
    else if (approch == EnumsType::PossibleApproch::Problem)
    {
        text = COMBO_BOX_APPROCH_PROBLEM_INFO;
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
    else if (type == EnumsType::PossibleType::NormalMerging)
    {
        text = COMBO_BOX_APPROCH_TYPE_NORMALMERGE_INFO;
    }
    else if (type == EnumsType::PossibleType::NormalProblem)
    {
        text = COMBO_BOX_APPROCH_TYPE_NORMALPROBLEM_INFO;
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
    else if(ui->comboBoxApproch->currentText() == COMBO_BOX_APPROCH_MERGING)
    {
        return EnumsType::PossibleApproch::Merging;
    }
    else if(ui->comboBoxApproch->currentText() == COMBO_BOX_APPROCH_PROBLEM)
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

    else if(ui->comboBoxType->currentText() == COMBO_BOX_APPROCH_TYPE_NORMALMERGE)
    {
        return EnumsType::PossibleType::NormalMerging;
    }

    else if(ui->comboBoxType->currentText() == COMBO_BOX_APPROCH_TYPE_NORMALPROBLEM)
    {
        return EnumsType::PossibleType::NormalProblem;
    }

    return EnumsType::PossibleType::None;
}
// ============================================================


