#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Accademy Project");

    QFile styleSheetFile("stylesheet.qss");

    if(!styleSheetFile.exists())
    {
        qDebug() << "File per lo Styles non esistente o non trovato";
    }
    else
    {
        qDebug() << "File per lo Style trovato";
        styleSheetFile.open(QFile::ReadOnly);
        QString StyleSheet = QLatin1String(styleSheetFile.readAll());
        qApp->setStyleSheet(StyleSheet);
        qDebug() << "Applico lo Style dentro il file";
    }

    w.show();

    qDebug() << "Starting the app:\n\n";
    return a.exec();
}
