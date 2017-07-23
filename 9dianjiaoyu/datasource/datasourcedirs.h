#ifndef DATASOURCEDIRS_H
#define DATASOURCEDIRS_H
#include <QList>
#include "../model/diritem.h"

class dataSourceDirs
{
private:
    dataSourceDirs();

public:
    static dataSourceDirs* GetInstance();

public:
    QList<diritem> getDirs();
    QList<diritem> getFiles(QString filePath);
};

#endif // DATASOURCEDIRS_H
