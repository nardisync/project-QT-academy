/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCreators;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QFrame *commandInputFrame;
    QVBoxLayout *verticalLayout_2;
    QFrame *inputFrame;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *centralVerticalLayout;
    QVBoxLayout *verticalLayoutApproch;
    QHBoxLayout *horizontalLayoutApproch;
    QLabel *labelApproch;
    QComboBox *comboBoxApproch;
    QSpacerItem *horizontalSpacerApproch;
    QLabel *labelApprochInfo;
    QVBoxLayout *verticalLayoutType;
    QHBoxLayout *horizontalLayoutType;
    QLabel *labelType;
    QComboBox *comboBoxType;
    QSpacerItem *horizontalSpacerType;
    QLabel *labelTypeInfo;
    QVBoxLayout *verticalLayoutRadio;
    QHBoxLayout *horizontalLayoutRadio;
    QFrame *frameRadioDifficult;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButtonEasy;
    QRadioButton *radioButtonMedium;
    QRadioButton *radioButtonHard;
    QSpacerItem *horizontalSpacerRadio;
    QLabel *labelRadioInfo;
    QHBoxLayout *horizontalLayoutButton;
    QPushButton *pushButtonApply;
    QSpacerItem *horizontalSpacerInputButton;
    QPushButton *pushButtonAppendThread;
    QPushButton *pushButtonAppendThreadStart;
    QLabel *labelInputInstructions;
    QFrame *commandOutputFrame;
    QVBoxLayout *rightVerticalLayout;
    QFrame *progressBarFrame;
    QVBoxLayout *verticalLayout_3;
    QListView *progressBarFrameListView;
    QTableView *logTableView;
    QMenuBar *menubar;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1600, 800);
        QPalette palette;
        MainWindow->setPalette(palette);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionCreators = new QAction(MainWindow);
        actionCreators->setObjectName(QString::fromUtf8("actionCreators"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        commandInputFrame = new QFrame(centralwidget);
        commandInputFrame->setObjectName(QString::fromUtf8("commandInputFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(commandInputFrame->sizePolicy().hasHeightForWidth());
        commandInputFrame->setSizePolicy(sizePolicy);
        commandInputFrame->setStyleSheet(QString::fromUtf8(""));
        commandInputFrame->setFrameShape(QFrame::StyledPanel);
        commandInputFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(commandInputFrame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        inputFrame = new QFrame(commandInputFrame);
        inputFrame->setObjectName(QString::fromUtf8("inputFrame"));
        inputFrame->setStyleSheet(QString::fromUtf8(""));
        inputFrame->setFrameShape(QFrame::StyledPanel);
        inputFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(inputFrame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        centralVerticalLayout = new QVBoxLayout();
        centralVerticalLayout->setObjectName(QString::fromUtf8("centralVerticalLayout"));
        centralVerticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayoutApproch = new QVBoxLayout();
        verticalLayoutApproch->setObjectName(QString::fromUtf8("verticalLayoutApproch"));
        horizontalLayoutApproch = new QHBoxLayout();
        horizontalLayoutApproch->setObjectName(QString::fromUtf8("horizontalLayoutApproch"));
        labelApproch = new QLabel(inputFrame);
        labelApproch->setObjectName(QString::fromUtf8("labelApproch"));
        labelApproch->setMinimumSize(QSize(60, 0));

        horizontalLayoutApproch->addWidget(labelApproch);

        comboBoxApproch = new QComboBox(inputFrame);
        comboBoxApproch->addItem(QString());
        comboBoxApproch->addItem(QString());
        comboBoxApproch->addItem(QString());
        comboBoxApproch->setObjectName(QString::fromUtf8("comboBoxApproch"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBoxApproch->sizePolicy().hasHeightForWidth());
        comboBoxApproch->setSizePolicy(sizePolicy1);

        horizontalLayoutApproch->addWidget(comboBoxApproch);

        horizontalSpacerApproch = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutApproch->addItem(horizontalSpacerApproch);


        verticalLayoutApproch->addLayout(horizontalLayoutApproch);

        labelApprochInfo = new QLabel(inputFrame);
        labelApprochInfo->setObjectName(QString::fromUtf8("labelApprochInfo"));

        verticalLayoutApproch->addWidget(labelApprochInfo);


        centralVerticalLayout->addLayout(verticalLayoutApproch);

        verticalLayoutType = new QVBoxLayout();
        verticalLayoutType->setObjectName(QString::fromUtf8("verticalLayoutType"));
        horizontalLayoutType = new QHBoxLayout();
        horizontalLayoutType->setObjectName(QString::fromUtf8("horizontalLayoutType"));
        labelType = new QLabel(inputFrame);
        labelType->setObjectName(QString::fromUtf8("labelType"));
        labelType->setMinimumSize(QSize(60, 0));

        horizontalLayoutType->addWidget(labelType);

        comboBoxType = new QComboBox(inputFrame);
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->setObjectName(QString::fromUtf8("comboBoxType"));
        sizePolicy1.setHeightForWidth(comboBoxType->sizePolicy().hasHeightForWidth());
        comboBoxType->setSizePolicy(sizePolicy1);

        horizontalLayoutType->addWidget(comboBoxType);

        horizontalSpacerType = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutType->addItem(horizontalSpacerType);


        verticalLayoutType->addLayout(horizontalLayoutType);

        labelTypeInfo = new QLabel(inputFrame);
        labelTypeInfo->setObjectName(QString::fromUtf8("labelTypeInfo"));

        verticalLayoutType->addWidget(labelTypeInfo);


        centralVerticalLayout->addLayout(verticalLayoutType);

        verticalLayoutRadio = new QVBoxLayout();
        verticalLayoutRadio->setObjectName(QString::fromUtf8("verticalLayoutRadio"));
        horizontalLayoutRadio = new QHBoxLayout();
        horizontalLayoutRadio->setObjectName(QString::fromUtf8("horizontalLayoutRadio"));
        frameRadioDifficult = new QFrame(inputFrame);
        frameRadioDifficult->setObjectName(QString::fromUtf8("frameRadioDifficult"));
        frameRadioDifficult->setFrameShape(QFrame::StyledPanel);
        frameRadioDifficult->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frameRadioDifficult);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButtonEasy = new QRadioButton(frameRadioDifficult);
        radioButtonEasy->setObjectName(QString::fromUtf8("radioButtonEasy"));
        radioButtonEasy->setChecked(true);

        horizontalLayout->addWidget(radioButtonEasy);

        radioButtonMedium = new QRadioButton(frameRadioDifficult);
        radioButtonMedium->setObjectName(QString::fromUtf8("radioButtonMedium"));

        horizontalLayout->addWidget(radioButtonMedium);

        radioButtonHard = new QRadioButton(frameRadioDifficult);
        radioButtonHard->setObjectName(QString::fromUtf8("radioButtonHard"));

        horizontalLayout->addWidget(radioButtonHard);


        horizontalLayoutRadio->addWidget(frameRadioDifficult);

        horizontalSpacerRadio = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutRadio->addItem(horizontalSpacerRadio);


        verticalLayoutRadio->addLayout(horizontalLayoutRadio);

        labelRadioInfo = new QLabel(inputFrame);
        labelRadioInfo->setObjectName(QString::fromUtf8("labelRadioInfo"));

        verticalLayoutRadio->addWidget(labelRadioInfo);


        centralVerticalLayout->addLayout(verticalLayoutRadio);

        horizontalLayoutButton = new QHBoxLayout();
        horizontalLayoutButton->setObjectName(QString::fromUtf8("horizontalLayoutButton"));
        pushButtonApply = new QPushButton(inputFrame);
        pushButtonApply->setObjectName(QString::fromUtf8("pushButtonApply"));
        pushButtonApply->setStyleSheet(QString::fromUtf8(""));

        horizontalLayoutButton->addWidget(pushButtonApply);

        horizontalSpacerInputButton = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutButton->addItem(horizontalSpacerInputButton);

        pushButtonAppendThread = new QPushButton(inputFrame);
        pushButtonAppendThread->setObjectName(QString::fromUtf8("pushButtonAppendThread"));

        horizontalLayoutButton->addWidget(pushButtonAppendThread);

        pushButtonAppendThreadStart = new QPushButton(inputFrame);
        pushButtonAppendThreadStart->setObjectName(QString::fromUtf8("pushButtonAppendThreadStart"));

        horizontalLayoutButton->addWidget(pushButtonAppendThreadStart);


        centralVerticalLayout->addLayout(horizontalLayoutButton);


        verticalLayout->addLayout(centralVerticalLayout);


        verticalLayout_2->addWidget(inputFrame);

        labelInputInstructions = new QLabel(commandInputFrame);
        labelInputInstructions->setObjectName(QString::fromUtf8("labelInputInstructions"));
        labelInputInstructions->setLayoutDirection(Qt::LeftToRight);
        labelInputInstructions->setStyleSheet(QString::fromUtf8(""));
        labelInputInstructions->setTextFormat(Qt::AutoText);
        labelInputInstructions->setScaledContents(false);
        labelInputInstructions->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        labelInputInstructions->setWordWrap(false);
        labelInputInstructions->setMargin(15);
        labelInputInstructions->setIndent(2);
        labelInputInstructions->setOpenExternalLinks(true);

        verticalLayout_2->addWidget(labelInputInstructions);


        horizontalLayout_2->addWidget(commandInputFrame);

        commandOutputFrame = new QFrame(centralwidget);
        commandOutputFrame->setObjectName(QString::fromUtf8("commandOutputFrame"));
        commandOutputFrame->setStyleSheet(QString::fromUtf8(""));
        rightVerticalLayout = new QVBoxLayout(commandOutputFrame);
        rightVerticalLayout->setObjectName(QString::fromUtf8("rightVerticalLayout"));
        progressBarFrame = new QFrame(commandOutputFrame);
        progressBarFrame->setObjectName(QString::fromUtf8("progressBarFrame"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(progressBarFrame->sizePolicy().hasHeightForWidth());
        progressBarFrame->setSizePolicy(sizePolicy2);
        progressBarFrame->setMinimumSize(QSize(0, 540));
        progressBarFrame->setMaximumSize(QSize(16777215, 16777215));
        progressBarFrame->setFrameShape(QFrame::StyledPanel);
        progressBarFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(progressBarFrame);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        progressBarFrameListView = new QListView(progressBarFrame);
        progressBarFrameListView->setObjectName(QString::fromUtf8("progressBarFrameListView"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(progressBarFrameListView->sizePolicy().hasHeightForWidth());
        progressBarFrameListView->setSizePolicy(sizePolicy3);

        verticalLayout_3->addWidget(progressBarFrameListView);


        rightVerticalLayout->addWidget(progressBarFrame);

        logTableView = new QTableView(commandOutputFrame);
        logTableView->setObjectName(QString::fromUtf8("logTableView"));
        logTableView->setMinimumSize(QSize(0, 0));
        logTableView->setMaximumSize(QSize(16777215, 16777215));
        logTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        logTableView->setAlternatingRowColors(false);
        logTableView->horizontalHeader()->setCascadingSectionResizes(true);
        logTableView->horizontalHeader()->setDefaultSectionSize(150);
        logTableView->horizontalHeader()->setStretchLastSection(true);
        logTableView->verticalHeader()->setVisible(false);
        logTableView->verticalHeader()->setMinimumSectionSize(35);
        logTableView->verticalHeader()->setStretchLastSection(false);

        rightVerticalLayout->addWidget(logTableView);


        horizontalLayout_2->addWidget(commandOutputFrame);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1600, 21));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuAbout->menuAction());
        menuAbout->addAction(actionCreators);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionCreators->setText(QCoreApplication::translate("MainWindow", "Creators", nullptr));
        labelApproch->setText(QCoreApplication::translate("MainWindow", "Approch :", nullptr));
        comboBoxApproch->setItemText(0, QCoreApplication::translate("MainWindow", "Sorting Algorithm", nullptr));
        comboBoxApproch->setItemText(1, QCoreApplication::translate("MainWindow", "Merging Algorithm", nullptr));
        comboBoxApproch->setItemText(2, QCoreApplication::translate("MainWindow", "Problem with Algorithm", nullptr));

        labelApprochInfo->setText(QString());
        labelType->setText(QCoreApplication::translate("MainWindow", "Type :", nullptr));
        comboBoxType->setItemText(0, QCoreApplication::translate("MainWindow", "BubbleSort", nullptr));
        comboBoxType->setItemText(1, QCoreApplication::translate("MainWindow", "QuickSort", nullptr));
        comboBoxType->setItemText(2, QCoreApplication::translate("MainWindow", "MergeSort", nullptr));
        comboBoxType->setItemText(3, QCoreApplication::translate("MainWindow", "NormalMerging", nullptr));
        comboBoxType->setItemText(4, QCoreApplication::translate("MainWindow", "NormalProblem", nullptr));

        labelTypeInfo->setText(QString());
        radioButtonEasy->setText(QCoreApplication::translate("MainWindow", "Easy", nullptr));
        radioButtonMedium->setText(QCoreApplication::translate("MainWindow", "Medium", nullptr));
        radioButtonHard->setText(QCoreApplication::translate("MainWindow", "Hard", nullptr));
        labelRadioInfo->setText(QString());
        pushButtonApply->setText(QCoreApplication::translate("MainWindow", "Start the Thread", nullptr));
        pushButtonAppendThread->setText(QCoreApplication::translate("MainWindow", "Append Thread", nullptr));
        pushButtonAppendThreadStart->setText(QCoreApplication::translate("MainWindow", "Start appended Thread", nullptr));
        labelInputInstructions->setText(QString());
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
