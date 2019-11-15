#ifndef MAP_MAKER_INIT_WORKER_HPP
#define MAP_MAKER_INIT_WORKER_HPP

#include <QtCore/QObject>

namespace map_builder
{
    class init_worker : public QObject
    {
       Q_OBJECT
    public:
        explicit init_worker(QObject *parent = nullptr);

    public slots:
       void start();
    signals:
        void finished();


    private:
    };
}
#endif //MAP_MAKER_INIT_WORKER_HPP
