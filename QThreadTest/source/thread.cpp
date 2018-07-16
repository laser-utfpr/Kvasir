
#include <iostream>
#include <QCore>

class Thread : public QThread
{
    Q_OBJECT

private:

protected:
    void run() override;

public:
    Thread();
    ~Thread();

signals:

public slots:

};

#include "moc_thread.cpp"
