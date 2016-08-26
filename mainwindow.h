#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnOk_clicked();

    void on_btnLoad_clicked();

private:
    Ui::MainWindow *ui;
    QString file;
    int w;
    int h;
};

#endif // MAINWINDOW_H
