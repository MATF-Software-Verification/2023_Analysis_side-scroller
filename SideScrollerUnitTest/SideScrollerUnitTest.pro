QT += testlib
QT += core gui multimedia

CONFIG += qt warn_on depend_includepath testcase
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

TEMPLATE = app

SOURCES += \
    tst_side_scroller.cpp \
    ../28-side-scroller/side-scroller/Babe.cpp \
    ../28-side-scroller/side-scroller/Block.cpp \
    ../28-side-scroller/side-scroller/Bullet.cpp \
    ../28-side-scroller/side-scroller/Button.cpp \
    ../28-side-scroller/side-scroller/Enemy.cpp \
    ../28-side-scroller/side-scroller/EnemyFinalBoss.cpp \
    ../28-side-scroller/side-scroller/EnemyPickman.cpp \
    ../28-side-scroller/side-scroller/EnemyProjectile.cpp \
    ../28-side-scroller/side-scroller/EnemySniperJoe.cpp \
    ../28-side-scroller/side-scroller/Entity.cpp \
    ../28-side-scroller/side-scroller/FinalBossBullet1.cpp \
    ../28-side-scroller/side-scroller/FinalBossBullet2.cpp \
    ../28-side-scroller/side-scroller/Game.cpp \
    ../28-side-scroller/side-scroller/HealthBar.cpp \
    ../28-side-scroller/side-scroller/Inert.cpp \
    ../28-side-scroller/side-scroller/LevelManager.cpp \
    ../28-side-scroller/side-scroller/Object.cpp \
    ../28-side-scroller/side-scroller/Pickaxe.cpp \
    ../28-side-scroller/side-scroller/Player.cpp \
    ../28-side-scroller/side-scroller/Projectile.cpp \
    ../28-side-scroller/side-scroller/Rocket.cpp \
    ../28-side-scroller/side-scroller/SniperJoeBullet.cpp \


SUBDIRS += \
    ../28-side-scroller/side-scroller/side-scroller.pro

HEADERS += \
    ../28-side-scroller/side-scroller/Babe.h \
    ../28-side-scroller/side-scroller/Block.h \
    ../28-side-scroller/side-scroller/Bullet.h \
    ../28-side-scroller/side-scroller/Button.h \
    ../28-side-scroller/side-scroller/Enemy.h \
    ../28-side-scroller/side-scroller/EnemyFinalBoss.h \
    ../28-side-scroller/side-scroller/EnemyPickman.h \
    ../28-side-scroller/side-scroller/EnemyProjectile.h \
    ../28-side-scroller/side-scroller/EnemySniperJoe.h \
    ../28-side-scroller/side-scroller/Entity.h \
    ../28-side-scroller/side-scroller/FinalBossBullet1.h \
    ../28-side-scroller/side-scroller/FinalBossBullet2.h \
    ../28-side-scroller/side-scroller/Game.h \
    ../28-side-scroller/side-scroller/HealthBar.h \
    ../28-side-scroller/side-scroller/Inert.h \
    ../28-side-scroller/side-scroller/LevelManager.h \
    ../28-side-scroller/side-scroller/Object.h \
    ../28-side-scroller/side-scroller/Pickaxe.h \
    ../28-side-scroller/side-scroller/Player.h \
    ../28-side-scroller/side-scroller/Projectile.h \
    ../28-side-scroller/side-scroller/Rocket.h \
    ../28-side-scroller/side-scroller/SniperJoeBullet.h \
    ../28-side-scroller/side-scroller/Utils.h
