#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include "EnumsType.h"

class Worker;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    // Getter
    EnumsType::PossibleApproch getApproch();
    EnumsType::Difficulty getDifficulty();
    EnumsType::PossibleType getType();


    // Setter
    // ....

    // Other
    QString addProgressBarToFrame(int taskID);

private slots:

    // Buttons Slot
    void on_pushButtonApply_clicked();
    void on_pushButtonAppendThread_clicked();
    void on_pushButtonAppendThreadStart_clicked();

    // Combo Box Slots
    void on_comboBoxApproch_currentTextChanged(const QString &comboApprochCurrentText);
    void on_comboBoxType_currentTextChanged(const QString &type);

    // Menu Slots
    void on_actionCreators_triggered();
    void customMenuRequested();

private:

    Ui::MainWindow *ui;
    Worker *worker;


    // Gestione delle Signals
    void sendSignalCalculate();


    // Update dei dati -> Gestione delle Combo Box d'Input
    void updateTypeComboBox(EnumsType::PossibleApproch approch);


    // Update dei dati -> Gestione delle Label info
    void updateApprochInfo(EnumsType::PossibleApproch approch);
    void updateDifficultyInfo(EnumsType::Difficulty difficulty);
    void updateTypeInfo(EnumsType::PossibleType type);


};
#endif // MAINWINDOW_H
