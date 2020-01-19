//
// Created by trifu on 1/18/2020.
//

#include <utils/ImportantEventFilter.hpp>
#include <QtGui/QDragMoveEvent>
#include <QDebug>
#include <QMetaObject>
#include <QMetaEnum>
#include <QVector2D>


//TODO: move to uitls credi to : https://stackoverflow.com/questions/22535469/how-to-get-human-readable-event-type-from-qevent
template<typename EnumType>
QString toString(const EnumType& enumValue)
{
    const char* enumName = qt_getEnumName(enumValue);
    const QMetaObject* metaObject = qt_getEnumMetaObject(enumValue);
    if (metaObject)
    {
        const int enumIndex = metaObject->indexOfEnumerator(enumName);
        return QString("%1::%2::%3").arg(metaObject->className(), enumName, metaObject->enumerator(enumIndex).valueToKey(enumValue));
    }

    return QString("%1::%2").arg(enumName).arg(static_cast<int>(enumValue));
}
namespace map_builder
{
    bool ImportantEventFilter::eventFilter(QObject *watched, QEvent *event)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            mPreviousPosition = QPoint(mouseEvent->x(), mouseEvent->y());
            mCurrentMouseButton = mouseEvent->button();
        }
        else if(event->type() == QEvent::MouseMove)
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

            if(!mDraged)
            {
                emit startDragEvent(mPreviousPosition, mCurrentMouseButton);
                mDraged = true;
            }

            QPoint currentPosition = QPoint(mouseEvent->x(), mouseEvent->y());
            QVector2D dragDirection = QVector2D(currentPosition)
                    - QVector2D(mPreviousPosition);

            mPreviousPosition = currentPosition;

            emit dragedEvent(dragDirection, mCurrentMouseButton);
        }
        else if(event->type() == QEvent::MouseButtonRelease)
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            const QPoint currentPoint(mouseEvent->x(), mouseEvent->y());

            if(!mDraged)
            {
                emit mouseClickedEvent(currentPoint, mouseEvent->button());
            }

            emit endDragEvent(currentPoint, mCurrentMouseButton);
            mDraged = false;
        }
        else if(event->type() == QEvent::Resize)
        {
            QResizeEvent *resizeEvent = static_cast<QResizeEvent*>(event);

            emit resizedEvent(resizeEvent->size());
        }
        else if(event->type() == QEvent::Wheel)
        {
            QWheelEvent *wheelEvent = static_cast<QWheelEvent *>(event);

            int angleDeltaY  = wheelEvent->angleDelta().y();
            if(angleDeltaY != 0)
            {
                emit scrollWheelEvent(angleDeltaY < 0 ? -1 : 1, wheelEvent->pos());
            }

        }

       return QObject::eventFilter(watched, event);
    }

    ImportantEventFilter::ImportantEventFilter(QObject *parent)
    :
            QObject(parent),
            mDraged{false},
            mPreviousPosition(0, 0)
    {}

}

