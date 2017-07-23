#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringListModel>
#include <QDir>
#include <QDebug>
#include "model/diritem.h"
#include "model/qleftdirlistmodel.h"
#include "datasource/datasourcedirs.h"
#include "common/datadefine.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->flash->setControl(QString::fromUtf8("{d27cdb6e-ae6d-11cf-96b8-444553540000}"));
    QString swfFile = qApp->applicationDirPath()+"/Resource/26个英文字母发音、笔画/a.swf"; // "http://www.firemail.wang/production_resource/temp/a.swf";
    ui->flash->dynamicCall("LoadMovie(long,string)",0,swfFile);

    //left
    QLeftDirListModel *model = new QLeftDirListModel(dataSourceDirs::GetInstance()->getDirs(), EMDT_DIR);
    ui->leftDirListView->setModel(model);
    connect(ui->leftDirListView,SIGNAL(clicked(QModelIndex)),this,SLOT(dirItemClicked(QModelIndex)));

    //right
   connect(ui->rightFilelistView,SIGNAL(clicked(QModelIndex)),this,SLOT(fileItemClicked(QModelIndex)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fileItemClicked(QModelIndex index)
{
    diritem *item = static_cast<diritem*>(index.internalPointer());
    if (item)
    {
       ui->flash->dynamicCall("LoadMovie(long,string)",0,item->absoluteFilePath);
    }
}

void MainWindow::dirItemClicked(QModelIndex index)
{
    diritem *item = static_cast<diritem*>(index.internalPointer());
    if (item)
    {
        QLeftDirListModel *modelFiles = new QLeftDirListModel(dataSourceDirs::GetInstance()->getFiles(item->absoluteFilePath), EMDT_FILE);
        ui->rightFilelistView->setModel(modelFiles);

    }

}

