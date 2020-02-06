#ifndef TESTLISTMODEL_H
#define TESTLISTMODEL_H

#include "TestListModelElement.h"
#include <QAbstractListModel>
#include <QObject>

class TestListModel : public QAbstractListModel {
    Q_OBJECT

public:
    enum TestListElementRole {
        RoleID = Qt::UserRole + 1,
        RoleLabel,
        RoleIsEnable
    };
    Q_ENUM(TestListElementRole)

    TestListModel(QObject* parent = nullptr);
    virtual ~TestListModel();

    virtual QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE virtual int rowCount(const QModelIndex& parent = QModelIndex()) const;
    Q_INVOKABLE virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

    void append(const TestListModelElement& item);
    void remove(const int& index);
    void removeRange(const int& first, const int& last);
    void changeData(const int& index, const TestListModelElement& item);
    const TestListModelElement& at(const int& index) const;

private:
    QHash<int, QByteArray> mRoles;
    QList<TestListModelElement> mListData;
};

#endif // TESTLISTMODEL_H
