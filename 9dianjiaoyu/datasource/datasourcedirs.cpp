#include <QDir>
#include <QApplication>
#include "datasourcedirs.h"

dataSourceDirs::dataSourceDirs()
{

}

dataSourceDirs* dataSourceDirs::GetInstance()
{
    static dataSourceDirs singleton;
    return &singleton;
}

QList<diritem> dataSourceDirs::getDirs()
{
    QList<diritem> resourceDirList;
    QDir dir(qApp->applicationDirPath()+"/Resource");

     foreach(QFileInfo mfi ,dir.entryInfoList())
     {
       if(mfi.isFile())
       {
           //qDebug()<< "File :" << mfi.fileName();
       }else
       {
           if(mfi.fileName()=="." || mfi.fileName() == "..")
               continue;
           //qDebug() << "Entry Dir" << mfi.absoluteFilePath();
           //chakan(mfi.absoluteFilePath());
           diritem diritemData;
           diritemData.absoluteFilePath = mfi.absoluteFilePath();
           diritemData.fileName = mfi.fileName();
           resourceDirList.push_back(diritemData);
       }
     }
     return resourceDirList;
}

QList<diritem> dataSourceDirs::getFiles(QString filePath)
{
    QList<diritem> resourceDirList;
    QDir dir(filePath);

     foreach(QFileInfo mfi ,dir.entryInfoList())
     {
       if(mfi.isFile())
       {
           diritem diritemData;
           diritemData.absoluteFilePath = mfi.absoluteFilePath();
           diritemData.fileName = mfi.fileName();
           resourceDirList.push_back(diritemData);
       }else
       {
           if(mfi.fileName()=="." || mfi.fileName() == "..")
               continue;
           //qDebug() << "Entry Dir" << mfi.absoluteFilePath();
           //chakan(mfi.absoluteFilePath());

       }
     }
     return resourceDirList;
}
