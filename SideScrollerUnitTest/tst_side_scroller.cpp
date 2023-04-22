#include <QtTest>
#include <QCoreApplication>


// add necessary includes here
#include <../28-side-scroller/side-scroller/Game.h>
#include <../28-side-scroller/side-scroller/Player.h>
#include <../28-side-scroller/side-scroller/Entity.h>
#include <../28-side-scroller/side-scroller/LevelManager.h>
#include <iostream>

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
    // kad je tek pokrenut MainMenu, prikazan je options (3 buttona)
    void testWhenGameIsInMainMenuThereAre3Buttons();
    // kad player die, onda je state GAME_OVER
    void testWhenPlayerDiesStateIsGameOver();
    // togglePause
    void testWhenTogglePauseGameStateIsPause();
    // ako je u Ready, i klikne se S, start se game, i state postaje RUNNING
    void testWhenGameStateIsReadyAndButtonPressKeySStateBecomesRunning();
    // ako je pritisnuto P, treba game state da bude PAUSED
    void testWhenButtonPressKeyPGameStateBecomesPaused();
    // ako je pritisnuo R dok je state Game_over, treba da postane Ready state
    void testWhenGameStateIsGameOverAndButtonPressKeyRStateBecomesReady();

};

side_scroller::side_scroller() {}

side_scroller::~side_scroller() {}

void side_scroller::initTestCase() {
}

void side_scroller::cleanupTestCase() {
    Game* game_instance = Game::instance();
    // TODO: Ili skroz obrisati delete, jer redovno radimo clear, ili moramo start, da bi se npr player psotavio, i onda brisi
    game_instance->start();
    delete game_instance;
}

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
    game_instance->reset();

}

void side_scroller::testIfWhenGameStartsPlayerIsInitialised() {
    Game* game_instance = Game::instance();
    game_instance->start();
    QVERIFY(game_instance->getPlayer() != nullptr);
    game_instance->reset();
}

void side_scroller::testWhenGameIsInMainMenuThereAre3Buttons() {
    Game* game_instance = Game::instance();
    // on prvo radi clear, pa postavlja 3 dugmeta!
    game_instance->displayMainMenu();

    // scene ima start, options, i quit button atm
    QCOMPARE(game_instance->getScene()->items().length(), 3);
    game_instance->reset();

}

void side_scroller::testWhenPlayerDiesStateIsGameOver() {
    Game* game_instance = Game::instance();
    game_instance->start();
    game_instance->getPlayer()->die();
    game_instance->gameover();

    game_state resulting_state = GAME_OVER;
    QCOMPARE(game_instance->getCur_state(), resulting_state);
    game_instance->reset();


}

void side_scroller::testWhenTogglePauseGameStateIsPause() {

    Game* game_instance = Game::instance();
    game_instance->setCur_state(RUNNING);
    game_instance->tooglePause();

    game_state resulting_state = PAUSE;
    QCOMPARE(game_instance->getCur_state(), resulting_state);
    game_instance->reset();

}

void side_scroller::testWhenGameStateIsReadyAndButtonPressKeySStateBecomesRunning() {
    Game* game_instance = Game::instance();

    game_instance->setCur_state(READY);
    game_instance->keyPressEvent(new QKeyEvent(QEvent::KeyPress, Qt::Key_S, Qt::NoModifier, "s"));

    game_state resulting_state = RUNNING;
    QCOMPARE(game_instance->getCur_state(), resulting_state);
    game_instance->reset();

}

void side_scroller::testWhenButtonPressKeyPGameStateBecomesPaused() {
    Game* game_instance = Game::instance();
    game_instance->start();
    game_instance->keyPressEvent(new QKeyEvent(QEvent::KeyPress, Qt::Key_P, Qt::NoModifier, "p"));

    game_state resulting_state = PAUSE;
    QCOMPARE(game_instance->getCur_state(), resulting_state);
    game_instance->reset();
}

void side_scroller::testWhenGameStateIsGameOverAndButtonPressKeyRStateBecomesReady() {
    Game* game_instance = Game::instance();

    game_instance->start();
    game_instance->setCur_state(GAME_OVER);
    game_instance->keyPressEvent(new QKeyEvent(QEvent::KeyPress, Qt::Key_R, Qt::NoModifier, "r"));

    game_state resulting_state = READY;
    QCOMPARE(game_instance->getCur_state(), resulting_state);
    game_instance->reset();
}



QTEST_MAIN(side_scroller)

#include "tst_side_scroller.moc"
