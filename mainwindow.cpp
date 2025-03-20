#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label_mouth->SetPixmaps(":/rc/mouth_1.png", ":/rc/mouth_2.png");
    ui->label_nose->SetPixmaps(":/rc/nose_1.png", ":/rc/nose_2.png");

    QObject::connect(ui->label_mouth, &CShapeLabel::mouseBtnClicked,
                     this, &MainWindow::onMouthClicked);
    QObject::connect(ui->label_nose, &CShapeLabel::mouseBtnClicked,
                     this, &MainWindow::onNoseClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onMouthClicked(QMouseEvent* ev)
{
    QMessageBox::information(this, "info", "MouthClicked");
}

void MainWindow::onNoseClicked(QMouseEvent* ev)
{
    QMessageBox::information(this, "info", "MouthClicked");
}

