#include "docs.h"

docs::docs(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant docs::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex docs::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex docs::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int docs::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int docs::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant docs::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
