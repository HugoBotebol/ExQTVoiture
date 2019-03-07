#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include"voiture.h"
#include<QDebug>

using namespace testing;
using namespace std;

class TestVoitureOccasionRouler: public Test
{
protected:
    int kilometrage;
    int jaugeCarburant;
    Voiture occasion;
    void SetUp() override {
        kilometrage = 160000;
        jaugeCarburant = 1500;
        occasion.setKilometrage(kilometrage);
        occasion.setJaugeCarburant(jaugeCarburant);
        occasion.setModele("Ferrari F40");
    }
    void TearDown() override {
        qDebug() << "Do some cleaning"<<endl;
    }
};

TEST_F(TestVoitureOccasionRouler,OK )
{
        //given
        int parcours = 100;
        //when
        occasion.rouler(parcours);
        //then
         EXPECT_EQ(occasion.kilometrage(),kilometrage+parcours)
                    << "Kilometrage incorrect"<< endl;
         EXPECT_EQ(occasion.jaugeCarburant(),jaugeCarburant-(parcours * 10))
                    <<"Jauge Carburant incorrect"<<endl;
}

TEST_F(TestVoitureOccasionRouler, NoGaz)
{
        //given
        int parcours = 200;
        //when/then
        EXPECT_THROW(occasion.rouler(parcours), std::invalid_argument);

         EXPECT_THAT(occasion.kilometrage(),Eq(kilometrage))
                    << "Kilometrage incorrect";
         EXPECT_EQ(occasion.jaugeCarburant(), jaugeCarburant)
                    <<"Jauge Carburant incorrect"<<endl;
}

class TestVoitureRouler: public TestWithParam <int>{
};

TEST_P(TestVoitureRouler, Neuve)
{
    //given
        QString modele = "Ferrari F40";
        int kilometrage = GetParam();
        int jaugeCarburant = 5000;
        int parcours = 200;
        Voiture voiture(modele,kilometrage,jaugeCarburant);
        //when
        voiture.rouler(parcours);
        //then
         EXPECT_THAT(voiture.kilometrage(),Eq(kilometrage+parcours))
                    << "Kilometrage incorrect";
         EXPECT_THAT(voiture.jaugeCarburant(), Eq(jaugeCarburant-(parcours * 5)))
                    <<"Jauge Carburant incorrect"<<endl;
}

INSTANTIATE_TEST_SUITE_P(GroupeNewCar,TestVoitureRouler,
                         //Values(0,10000,149999,150000
                          Range(0,150000,10000
                                ));



TEST(TestVoitureRouler, Exception)
{
    //given
        QString modele = "Ferrari F40";
        int kilometrage = 10000;
        int jaugeCarburant = 50;
        int parcours = 200;
        Voiture voiture(modele,kilometrage,jaugeCarburant);

        //when/then
        EXPECT_THROW(voiture.rouler(parcours), std::invalid_argument);

         EXPECT_EQ(voiture.kilometrage(),kilometrage)
                    << "Kilometrage incorrect";
         EXPECT_EQ(voiture.jaugeCarburant(), jaugeCarburant)
                    <<"Jauge Carburant incorrect"<<endl;
}
