#include <QtTest>
#include <QCoreApplication>


// add necessary includes here
#include <../28-side-scroller/side-scroller/Game.h>
#include <../28-side-scroller/side-scroller/Player.h>
#include <../28-side-scroller/side-scroller/Entity.h>
#include <../28-side-scroller/side-scroller/Enemy.h>
#include <../28-side-scroller/side-scroller/LevelManager.h>
#include <../28-side-scroller/side-scroller/EnemyPickman.h>

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
//    void testWhenButtonPressKeyPGameStateBecomesPaused();
    // ako je pritisnuo R dok je state Game_over, treba da postane Ready state
    void testWhenGameStateIsGameOverAndButtonPressKeyRStateBecomesReady();

    // Player
    // test da li mu je dobro startno x i y postavljeno
    void testIfDefaultXAndYAreCorrect();
    // ako Player izgubi 1 hp, treba da ima za 1 manje od maksimuma
    void testIfPlayerLosesCorrectHP();
    // kad primi previse hp, da li umre?
    void testIfPlayerDiesWhenHPNegative();
    // provera da li se brzina duplira ako se postavi na running
    void testIfSpeedIsDoubledWhenRunning();
    // ako je krenuo skok, da li je postavljena promenljiva jumping na true
    void testIfJumpingIsSetToTrueWhenThePlayerStartsJumping();

    // Enemy
    // ako se Enemy pomerio u desno, nova pozicija bi trebala > od stare (svi imaju isti metod, tako da samo 1 proizovljan)
    void testIfWhenEnemyMovesToTheRightItsXValueIsGreater();
    // ista stvar kao gore
    void testIfWhenEnemyMovesToTheLeftItsXValueIsLesser();
    // kad se spawn neprijatelj, on ce falling podrazumevano, da li mu je y manje?
    void testIfWhenEnemySpawnsHeIsFallingAndHisYIsGreaterThanBefore();
    // kad neprijatelj skace, y se povecava
    void testIfWhenEnemyJumpsHisYIsLesserThanBefore();

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

//void side_scroller::testWhenButtonPressKeyPGameStateBecomesPaused() {
//    Game* game_instance = Game::instance();
//    game_instance->start();
//    game_instance->keyPressEvent(new QKeyEvent(QEvent::KeyPress, Qt::Key_P, Qt::NoModifier, "p"));

//    game_state resulting_state = PAUSE;
//    QCOMPARE(game_instance->getCur_state(), resulting_state);
//    game_instance->reset();
//}

void side_scroller::testWhenGameStateIsGameOverAndButtonPressKeyRStateBecomesReady() {
    Game* game_instance = Game::instance();

    game_instance->start();
    game_instance->setCur_state(GAME_OVER);
    game_instance->keyPressEvent(new QKeyEvent(QEvent::KeyPress, Qt::Key_R, Qt::NoModifier, "r"));

    game_state resulting_state = READY;
    QCOMPARE(game_instance->getCur_state(), resulting_state);
    game_instance->reset();
}

void side_scroller::testIfDefaultXAndYAreCorrect() {
    int default_x = 350;
    int default_y = 350;
    Player* current_player = new Player(QPoint(default_x, default_y));

    QCOMPARE(current_player->x, default_x);
    QCOMPARE(current_player->y, default_y);
    delete current_player;
}

void side_scroller::testIfPlayerLosesCorrectHP() {
    Player* current_player = new Player(QPoint(350, 350));
    int dmg_dealt = 3;
    int max_hp = current_player->health;
    current_player->damagePlayer(dmg_dealt);

    QCOMPARE(max_hp - dmg_dealt, current_player->health);
    delete current_player;
}

void side_scroller::testIfPlayerDiesWhenHPNegative() {
    Player* current_player = new Player(QPoint(350, 350));
    int dmg_dealt = 25;
    current_player->damagePlayer(dmg_dealt);

    QCOMPARE(current_player->getDying(), true);
    delete current_player;
}

void side_scroller::testIfSpeedIsDoubledWhenRunning() {

    Player* current_player = new Player(QPoint(350, 350));
    int starting_moving_speed = current_player->getMoving_speed();
    current_player->setRunning(true);

    QCOMPARE(starting_moving_speed * 2, current_player->getMoving_speed());
    delete current_player;

}

void side_scroller::testIfJumpingIsSetToTrueWhenThePlayerStartsJumping() {

    Player* current_player = new Player(QPoint(350, 350));
    current_player->setFalling(false);
    current_player->jump();

    QCOMPARE(current_player->getJumping(), true);
    delete current_player;

}


// Enemy
void side_scroller::testIfWhenEnemyMovesToTheRightItsXValueIsGreater() {

    Enemy* current_enemy = (Enemy*) new EnemyPickman();
    current_enemy->setDirection(RIGHT);

    int old_x_value = current_enemy->x();

    // za testiranje nam je potreban i player, zato pokrecemo funkciju start
    Game::instance()->start();

    current_enemy->setMoving(true);
    current_enemy->advance();

    QVERIFY(current_enemy->x() > old_x_value);
    delete current_enemy;
    Game::instance()->reset();
}

// Enemy
void side_scroller::testIfWhenEnemyMovesToTheLeftItsXValueIsLesser() {

    Enemy* current_enemy = (Enemy*) new EnemyPickman();

    current_enemy->setX(1000);

    int old_x_value = current_enemy->x();
    Game::instance()->start();

    current_enemy->setMoving(true);
    current_enemy->setDirection(LEFT);
    current_enemy->advance();

    QVERIFY(current_enemy->x() < old_x_value);
    delete current_enemy;
    Game::instance()->reset();
}

void side_scroller::testIfWhenEnemySpawnsHeIsFallingAndHisYIsGreaterThanBefore() {

    Enemy* current_enemy = (Enemy*) new EnemyPickman();

    int old_y_value = current_enemy->y();
    Game::instance()->start();
    current_enemy->advance();

    QVERIFY(current_enemy->y() > old_y_value);
    delete current_enemy;
    Game::instance()->reset();

}

void side_scroller::testIfWhenEnemyJumpsHisYIsLesserThanBefore() {

    Enemy* current_enemy = (Enemy*) new EnemyPickman();

    current_enemy->setY(1000);
    current_enemy->setFalling(false);
    current_enemy->setJumping(true);

    int old_y_value = current_enemy->y();
    Game::instance()->start();
    current_enemy->advance();

    QVERIFY(current_enemy->y() < old_y_value);
    delete current_enemy;
    Game::instance()->reset();

}



QTEST_MAIN(side_scroller)

#include "tst_side_scroller.moc"
