include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread


HEADERS += \
    tst_testvoitureconstructor.h \
    tst_testvoitureroule.h \
    ../VoitureAppli/tst_testpilotevoiture.h

SOURCES += \
        main.cpp

include (../VoitureAppli/voiture.pri)
INCLUDEPATH += ../VoitureAppli
