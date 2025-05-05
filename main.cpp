#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QGraphicsView>
#include "playscreen.h"
#include "player.h"
#include "scene.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Translation setup
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "EscapeThePROFESSOR_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    // Load PlayScreen (Level selection screen)
    PlayScreen w;
    w.show();

    return app.exec();
}

