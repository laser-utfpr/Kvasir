#ifndef SMMCTHREAD_HPP
#define SMMCTHREAD_HPP

#include <QtCore>

#include <iostream>

class SMMCThread : public QThread
{
    Q_OBJECT

private:

protected:
    void run() override;

public:
    SMMCThread();
    ~SMMCThread();
    //void manageSharedMemory(void);

signals:
    //something changed
};

#endif // SMMCTHREAD_HPP
