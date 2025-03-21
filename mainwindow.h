#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public Q_SLOTS:
    void onMouthClicked(QMouseEvent* ev);
    void onNoseClicked(QMouseEvent* ev);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
