#include <QtTest>
#include <QCoreApplication>


// add necessary includes here
#include <../28-side-scroller/side-scroller/Game.h>


class side_scroller : public QObject
{
    Q_OBJECT

public:
    side_scroller();
    ~side_scroller();

private slots:
    void initTestCase();
    void cleanupTestCase();
    
    // Game
    // Proverava da li je Game klasa stvarno singleton!
    void testIfGameIsSingleInstance();
    // Proverava da li je cur_state na samom pocetku igrice READY!
    void testIfGameStateIsReadyAtTheBegining();
    // Proverava da li kad je Game startovan, je cur_sstate postavljen na RUNNING!
    void testIfGameStateIsRunningWhenGameStarts();
    // Proverava da li kad je Game startovan, je Player postavljen na vrednost koja nije null!
    void testIfWhenGameStartsPlayerIsInitialised();
    // kad je tek pokrenuta igrica, prikazan je options (3 buttona)
    void testWhenGameIsInMainMenuThereAre3Buttons();

};

side_scroller::side_scroller() {}

side_scroller::~side_scroller() {}

void side_scroller::initTestCase() {}

void side_scroller::cleanupTestCase() {}

// Game class

void side_scroller::testIfGameIsSingleInstance() {
    Game* game_first_instance = Game::instance();
    Game* game_second_instance = Game::instance();
    QCOMPARE(game_first_instance, game_second_instance);
}

void side_scroller::testIfGameStateIsReadyAtTheBegining() {
    Game* game_instance = Game::instance();
    game_state resulting_state = READY;
    QCOMPARE(game_instance->getCur_state(), resulting_state);
}

void side_scroller::testIfGameStateIsRunningWhenGameStarts() {
    Game* game_instance = Game::instance();
    game_instance->start();
    game_state resulting_state = RUNNING;
    QCOMPARE(game_instance->getCur_state(), resulting_state);
}

void side_scroller::testIfWhenGameStartsPlayerIsInitialised() {
    Game* game_instance = Game::instance();
    game_instance->start();
    QVERIFY(game_instance->getPlayer() != nullptr);
}

void side_scroller::testWhenGameIsInMainMenuThereAre3Buttons() {
    Game* game_instance = Game::instance();
    // on prvo radi clear, pa postavlja 3 dugmeta!
    game_instance->displayMainMenu();

    // scene ima start, options, i quit button atm
    QCOMPARE(game_instance->getScene()->items().length(), 3);
}


QTEST_MAIN(side_scroller)

#include "tst_side_scroller.moc"
