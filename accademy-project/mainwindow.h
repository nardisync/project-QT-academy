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

    EnumsType::PossibleApproch getApproch();
    EnumsType::PossibleType getType();
    EnumsType::Difficulty getDifficulty();

private slots:
    void on_pushButtonApply_clicked();
    void on_pushButtonAppendThread_clicked();
    void on_pushButtonAppendThreadStart_clicked();

    void on_comboBoxApproch_currentTextChanged(const QString &comboApprochCurrentText);
    void on_comboBoxType_currentTextChanged(const QString &type);

private:
    Ui::MainWindow *ui;
    Worker *worker;

    void sendSignalCalculate();

    /* Gestione delle Combo Box d'Input */
    void updateTypeComboBox(EnumsType::PossibleApproch approch);

    /* Gestione delle Label info */
    void updateApprochInfo(EnumsType::PossibleApproch approch);
    void updateTypeInfo(EnumsType::PossibleType type);
    void updateDifficultyInfo(EnumsType::Difficulty difficulty);

};
#endif // MAINWINDOW_H
