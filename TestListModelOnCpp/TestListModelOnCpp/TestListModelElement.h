#ifndef TESTLISTMODELELEMENT_H
#define TESTLISTMODELELEMENT_H

#include <QString>

class TestListModelElement {
public:
    TestListModelElement(const int& id, const QString& label, const bool& isEnable);
    virtual ~TestListModelElement() {}
    TestListModelElement(const TestListModelElement& rhs);

    TestListModelElement& operator=(const TestListModelElement& rhs);

    const int& id() const;
    void setID(const int& id);

    const QString& label() const;
    void setlabel(const QString& label);

    const bool& isEnable() const;
    void setIsEnable(const bool& isEnable);

private:
    int mID;
    QString mLabel;
    bool mIsEnable;
};

#endif // TESTLISTMODELELEMENT_H
