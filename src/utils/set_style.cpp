#include <utils/set_style.hpp>
#include <QString>
#include <QFontDatabase>
#include <QFile>

void set_style_to_widget(QWidget *widget)
{
    static const QString style_path(":/styles/style.qss");
    static QString style;
    static bool first{true};

    if(first)
    {
        QFontDatabase::addApplicationFont(":/styles/styles/medieval_sharp.ttf");

        QFile style_file = QFile(style_path);
        style_file.open(QFile::ReadOnly);
        style = QLatin1String(style_file.readAll());

        first = false;
    }

    widget->setStyleSheet(style);
}


