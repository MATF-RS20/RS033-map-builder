#ifndef MAP_MAKER_INIT_WORKER_HPP
#define MAP_MAKER_INIT_WORKER_HPP

#include <memory>
#include <QtCore/QObject>
#include "comunicator.hpp"
#include "comunication/communication_config.hpp"
#include "comunication/splash_screen_comunicatior.hpp"

namespace map_builder
{
    class init_worker : public QObject
    {
       Q_OBJECT
    public:
        explicit init_worker(comunicator_type *com, QObject *parent = nullptr);

    public slots:
       void start();
    signals:
        void finished();


    private:
        comunicator_type *m_com;
    };
}
#endif //MAP_MAKER_INIT_WORKER_HPP
