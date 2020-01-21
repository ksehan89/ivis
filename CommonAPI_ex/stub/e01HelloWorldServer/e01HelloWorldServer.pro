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

SOURCES += \
        /home/ubuntu/CommonAPI_ex/src-gen/v0/commonapi/examples/E01HelloWorldDBusDeployment.cpp \
        /home/ubuntu/CommonAPI_ex/src-gen/v0/commonapi/examples/E01HelloWorldDBusStubAdapter.cpp \
        /home/ubuntu/CommonAPI_ex/src-gen/v0/commonapi/examples/E01HelloWorldStubDefault.cpp \
        E01HelloWorldStubImpl.cpp \
        main.cpp

RESOURCES += qml.qrc

INCLUDEPATH +=  /home/ubuntu/CommonAPI_ex/src-gen \
                /opt/GENIVI/include/CommonAPI-3.1 \
                /opt/GENIVI/include/dbus-1.0 \
                /opt/GENIVI/lib/dbus-1.0/include

LIBS += -L/opt/GENIVI/lib -lCommonAPI \
        -L/opt/GENIVI/lib -lCommonAPI-DBus \
        -L/opt/GENIVI/lib -ldbus-1 \
        -L/opt/GENIVI/lib -ldlt

HEADERS += \
            /home/ubuntu/CommonAPI_ex/src-gen/v0/commonapi/examples/E01HelloWorld.hpp \
            /home/ubuntu/CommonAPI_ex/src-gen/v0/commonapi/examples/E01HelloWorldDBusDeployment.hpp \
            /home/ubuntu/CommonAPI_ex/src-gen/v0/commonapi/examples/E01HelloWorldDBusStubAdapter.hpp \
            /home/ubuntu/CommonAPI_ex/src-gen/v0/commonapi/examples/E01HelloWorldStub.hpp \
            /home/ubuntu/CommonAPI_ex/src-gen/v0/commonapi/examples/E01HelloWorldStubDefault.hpp \
            E01HelloWorldStubImpl.h

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
