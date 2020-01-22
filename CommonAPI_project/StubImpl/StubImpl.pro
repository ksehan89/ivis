QT += quick

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
                /opt/GENIVI/include \
                /opt/GENIVI/include/CommonAPI-3.1 \
                /opt/GENIVI/include/dbus-1.0 \
                /opt/GENIVI/include/dlt \
                /opt/GENIVI/lib/dbus-1.0/include \
                /home/ubuntu/ivis/CommonAPI_project/src-gen \
#                /home/ubuntu/ivis/dlt_test \
#                /home/ubuntu/ivis/DltRegistration \

SOURCES += \
        /home/ubuntu/ivis/CommonAPI_project/src-gen/v1/proj/testcode/Test_CodeDBusDeployment.cpp \
        /home/ubuntu/ivis/CommonAPI_project/src-gen/v1/proj/testcode/Test_CodeDBusStubAdapter.cpp \
        /home/ubuntu/ivis/CommonAPI_project/src-gen/v1/proj/testcode/Test_CodeStubDefault.cpp \
        /home/ubuntu/ivis/CommonAPI_project/src-gen/v1/proj/testcode/CommonTypesDBusDeployment.cpp \
#        /home/ubuntu/ivis/dlt_test \
#        /home/ubuntu/ivis/DltRegistration/dltregistration.cpp \
        HelloStubMain.cpp \
        main.cpp \

LIBS += \
        -L/opt/GENIVI/lib -lCommonAPI \
        -L/opt/GENIVI/lib -lCommonAPI-DBus \
        -L/opt/GENIVI/lib -ldbus-1 \
        -L/opt/GENIVI/lib -ldlt \
        -L/home/ubuntu/ivis/DltRegistration/deploy -lDltRegistration \

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    HelloStubMain.h
