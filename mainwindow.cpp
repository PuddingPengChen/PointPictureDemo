#include <QSvgRenderer>
#include <QFileDialog>
#include <QProcess>
#include <QDebug>
#include <QPainter>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    w = 1000;
    h = 1000;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnOk_clicked()
{
    QProcess* free = new QProcess();
    QFile::remove("out.svg");
    QStringList pp;


//    pp.append(tr("-s %1").arg());
//    pp.append(tr("-z %1").arg(ui->pointCount_2->text().toDouble()));
    pp<<"-s"<<tr("%1").arg(ui->pointCount->text().toInt())<<"-z"<<tr("%1").arg(ui->pointCount_2->text().toDouble());

    pp.append(file);
    pp.append("out.svg");

    if(free->execute("./voronoi.exe",pp))
    {
        qDebug()<<"load finished!!";
    }

    // Load your SVG
    QSvgRenderer renderer(QString("./out.svg"));

    // Prepare a QImage with desired characteritisc
    QImage image(w, h, QImage::Format_ARGB32);
//    image.fill(0xaaA08080);  // partly transparent red-ish background

    // Get QPainter that paints to the image
    QPainter painter(&image);
    renderer.render(&painter);
    ui->source2->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_btnLoad_clicked()
{
   file = QFileDialog::getOpenFileName(this,tr("Open"),".",tr("Image (*.png *jpg *.jpeg)"));
    if((QFileInfo(file).suffix()!="png")||((QFileInfo(file).suffix()!="PNG")))
    {
        QImage ds(file);
        ds.save("temp.png","PNG",100);
        file = "temp.png";
    }
    QImage d(file);
    w = d.width();
    h = d.height();
    ui->source1->setPixmap(QPixmap(file));
}
