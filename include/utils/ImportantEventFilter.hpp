#ifndef MAP_MAKER_IMPORTANTEVENTFILTER_HPP
#define MAP_MAKER_IMPORTANTEVENTFILTER_HPP

#include <QtCore/QObject>
#include <QPoint>
#include <QVector2D>
#include <QSize>

namespace map_builder
{
    class ImportantEventFilter : public QObject
    {
        Q_OBJECT

    public:
        ImportantEventFilter(QObject *parent);
    signals:
        void startDragEvent(QPoint pointOfStart, Qt::MouseButton button);
        void endDragEvent(QPoint pointOfEnd, Qt::MouseButton button);
        void dragedEvent(QVector2D dragDirection, Qt::MouseButton button);
        void mouseClickedEvent(QPoint point, Qt::MouseButton button);
        void resizedEvent(QSize size);
        /**
         *
         * @param direction -1 for toward user 1 from user
         */
        void scrollWheelEvent(int direction, QPoint point);

    private:
        bool mDraged;
        QPoint mPreviousPosition;
        Qt::MouseButton mCurrentMouseButton;

        bool eventFilter(QObject *watched, QEvent *event) override;
    };
}

#endif //MAP_MAKER_IMPORTANTEVENTFILTER_HPP
