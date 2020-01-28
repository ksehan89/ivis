#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    // QGuiApplication을 사용하기 위해 변수 app을 선언해 준다. Gui application 제어하기 위해.

    QQmlApplicationEngine engine;
    // QQmlApplicationEngine을 사용하기 위해 변수 engine을 선언해 준다. Q_Slots load함수 사용하기 위해.
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    // Qurl을 사용하기 위해 변수 url을 선언해주고, 해당 url값은 문자열 "qrc:/main.qml"을 넣어준다.

    //    qDebug() << "url0 : " << url;

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject* obj, const QUrl& objUrl) {
        // QObject의 connect 함수를 사용하기 위해
        // connect(const typename QtPrivate::FunctionPointer<Func1>::Object *sender, Func1 signal, const QObject *context, Func2 slot, Qt::ConnectionType type = Qt::AutoConnection)
        // *sender : &engine, signal : &QQmlApplicationEngine::objectCreated, *context : &app, slot : [url](QObject* obj, const QUrl& objUrl

        //        qDebug() << "url : " << url;
        //        qDebug() << "obj : " << obj;
        //        qDebug() << "objUrl : " << objUrl;
        if (!obj && url == objUrl) // object가 존재하고, 입력한 url과 입력받은 objUrl이 같으면 QCoreApplication 종료
            QCoreApplication::exit(-1);
    },
        Qt::QueuedConnection); // 연결

    engine.load(url); // QQmlApplicationEngine의 engine에 입력한 해당 url을 로드시킨다.

    return app.exec(); // app 실행
}
