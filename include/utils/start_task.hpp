#ifndef MAP_MAKER_START_TASK_HPP
#define MAP_MAKER_START_TASK_HPP

#include <utility>
#include <QtCore/QThread>

namespace map_builder::utils
{
    template<typename Worker, typename Communicator, typename ...WorkerArguments>
    void start_task(Communicator *&&communicator, WorkerArguments&&... workerArguments)
    {
        Worker *worker{new Worker(communicator, std::forward<WorkerArguments>(workerArguments)...)};
        QThread *thread{new QThread};

        worker->moveToThread(thread);

        QObject::connect(thread, &QThread::started, worker, &Worker::start);
        //When worker finishes it stops the thread
        QObject::connect(worker, &Worker::finished, thread, &QThread::quit);
        //When thread is killed it deletes worker
        QObject::connect(thread, &QThread::finished, worker, &Worker::deleteLater);
        //When thread is killed it deletes itself
        QObject::connect(thread, &QThread::finished, thread, &QThread::deleteLater);
        //When thread is killed it deletes communication chanel
        QObject::connect(thread, &QThread::finished, communicator, &QObject::deleteLater);

        thread->start();
    }
}
#endif //MAP_MAKER_START_TASK_HPP
