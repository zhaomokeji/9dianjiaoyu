#ifndef QLEFTDIRLISTMODEL_H
#define QLEFTDIRLISTMODEL_H
#include <QAbstractListModel>
#include "diritem.h"
#include "common/datadefine.h"

class QLeftDirListModel : public QAbstractListModel
{
public:
    QLeftDirListModel(QList<diritem> listItems, EModelDataType dataType);

public:
    QModelIndex index(int row, int column = 0, const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                                   int role = Qt::DisplayRole) const;
private:
    int columnCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    QList<diritem*> m_listOfDirItems;

    EModelDataType m_dataType;
};

#endif // QLEFTDIRLISTMODEL_H
