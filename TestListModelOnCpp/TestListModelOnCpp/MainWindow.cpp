#include "MainWindow.h"

MainWindow::MainWindow(QQuickView* parent)
    : QQuickView(parent)
    , mUrl()
    , mTestListModel()
{
    rootContext()->setContextProperty("MainWindow", this);
    rootContext()->setContextProperty("TestListModel", &mTestListModel);

    TestListModelElement item1(1, "label1", true);
    TestListModelElement item2(2, "label2", false);
    TestListModelElement item3(3, "label3", true);
    TestListModelElement item4(4, "label4", false);
    TestListModelElement item5(5, "label5", true);

    mTestListModel.append(item1);
    mTestListModel.append(item2);
    mTestListModel.append(item3);
    mTestListModel.append(item4);
    mTestListModel.append(item5);

    mTestListModel.changeData(4, item1);

    //mTestListModel.remove(0);
    //mTestListModel.removeRange(0, 1); // first, last
}

void MainWindow::loadQml(const QUrl source)
{
    mUrl = source;
    setSource(source);
}
