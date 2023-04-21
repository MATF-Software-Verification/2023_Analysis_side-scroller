#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class side_scroller : public QObject
{
    Q_OBJECT

public:
    side_scroller();
    ~side_scroller();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

side_scroller::side_scroller()
{

}

side_scroller::~side_scroller()
{

}

void side_scroller::initTestCase()
{

}

void side_scroller::cleanupTestCase()
{

}

void side_scroller::test_case1()
{

}

QTEST_MAIN(side_scroller)

#include "tst_side_scroller.moc"
