#include "TestListModelElement.h"

TestListModelElement::TestListModelElement(const int& id, const QString& label, const bool& isEnable)
    : mID(id)
    , mLabel(label)
    , mIsEnable(isEnable)
{
}

TestListModelElement::TestListModelElement(const TestListModelElement& rhs)
{
    *this = rhs;
}

TestListModelElement& TestListModelElement::operator=(const TestListModelElement& rhs)
{
    if (this != &rhs) {
        mID = rhs.mID;
        mLabel = rhs.mLabel;
        mIsEnable = rhs.mIsEnable;
    }
    return *this;
}

const int& TestListModelElement::id() const
{
    return mID;
}

void TestListModelElement::setID(const int& id)
{
    if (mID != id) {
        mID = id;
    }
}

const QString& TestListModelElement::label() const
{
    return mLabel;
}

void TestListModelElement::setlabel(const QString& label)
{
    if (mLabel != label) {
        mLabel = label;
    }
}

const bool& TestListModelElement::isEnable() const
{
    return mIsEnable;
}

void TestListModelElement::setIsEnable(const bool& isEnable)
{
    if (mIsEnable != isEnable) {
        mIsEnable = isEnable;
    }
}
