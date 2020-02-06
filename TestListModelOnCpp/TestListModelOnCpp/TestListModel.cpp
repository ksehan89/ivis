#include "TestListModel.h"

TestListModel::TestListModel(QObject* parent)
    : mRoles()
    , mListData()
{
    mRoles[RoleID] = "id";
    mRoles[RoleLabel] = "label";
    mRoles[RoleIsEnable] = "isEnable";
}

TestListModel::~TestListModel()
{
}

QHash<int, QByteArray> TestListModel::roleNames() const
{
    return mRoles;
}

int TestListModel::rowCount(const QModelIndex& parent) const
{
    return mListData.count();
}

QVariant TestListModel::data(const QModelIndex& index, int role) const
{
    int indexRow = index.row();
    int rowCnt = rowCount();

    if ((indexRow < 0) && (indexRow >= rowCnt)) {
        return QVariant();
    }

    const TestListModelElement& item = mListData[indexRow];

    QVariant variant;

    switch (role) {
    case RoleID:
        variant = item.id();
        break;
    case RoleLabel:
        variant = item.label();
        break;
    case RoleIsEnable:
        variant = item.isEnable();
        break;
    default:
        variant = QVariant();
        break;
    }

    return variant;
}

void TestListModel::append(const TestListModelElement& item)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    mListData.append(item);
    endInsertRows();
}

void TestListModel::remove(const int& index)
{
    int rowCnt = rowCount();

    if ((index < 0) || (index >= rowCnt)) {
        return;
    }

    beginRemoveRows(QModelIndex(), index, index);
    mListData.removeAt(index);
    endRemoveRows();
}

void TestListModel::removeRange(const int& first, const int& last)
{

    int rowCnt = rowCount();

    if ((first < 0) || (first >= rowCnt)) {
        return;
    }

    if ((last < 0) || (last >= rowCnt)) {
        return;
    }

    if (first > last) {
        return;
    }

    beginRemoveRows(QModelIndex(), first, last);
    for (int32_t i = last; i >= first; i--) {
        mListData.removeAt(i);
    }
    endRemoveRows();
}

void TestListModel::changeData(const int& index, const TestListModelElement& item)
{
    int rowCnt = rowCount();

    if ((index < 0) || (index >= rowCnt)) {
        return;
    }

    mListData.replace(index, item);

    emit dataChanged(this->index(index), this->index(index));
}

const TestListModelElement& TestListModel::at(const int& index) const
{
    return mListData.at(index);
}
