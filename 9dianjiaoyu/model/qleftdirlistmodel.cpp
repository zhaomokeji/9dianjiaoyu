#include "qleftdirlistmodel.h"

QLeftDirListModel::QLeftDirListModel(QList<diritem> listItems, EModelDataType dataType)
{
    for (int i = 0; i < listItems.size(); ++i) {
        diritem * pDirItem = new diritem();
        pDirItem->absoluteFilePath = listItems.at(i).absoluteFilePath;
        pDirItem->fileName = listItems.at(i).fileName;
        m_listOfDirItems.push_back(pDirItem);
      }
    m_dataType = dataType;
}

QModelIndex QLeftDirListModel::index(int row, int column, const QModelIndex &parent) const
{
    if (parent.isValid())
        return QModelIndex();

    if (row >= m_listOfDirItems.size() || row < 0)
        return QModelIndex();
     diritem *pDirItem = m_listOfDirItems.at(row);
     if (NULL == pDirItem)
     {
         return QModelIndex();
     }
      return createIndex(row, column, pDirItem);
}

int QLeftDirListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return DEFAULT_VALUE_ZERO;
    return m_listOfDirItems.size();
}

QVariant QLeftDirListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (Qt::DisplayRole == role) {
        diritem *item = static_cast<diritem*>(index.internalPointer());
        if (item)
           return item->fileName;
    }
    return QVariant();
}

QVariant QLeftDirListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return tr("Name");

            case 1:
                return tr("Path");

            default:
                return QVariant();
        }
    }
    return QVariant();
}


int QLeftDirListModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return DEFAULT_VALUE_ZERO;
    if(m_dataType == EMDT_DIR){
        return 1;
    }
    else {
        return 2;
    }
}
