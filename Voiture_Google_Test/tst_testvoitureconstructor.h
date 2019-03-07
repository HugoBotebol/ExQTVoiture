#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include"voiture.h"

using namespace testing;

TEST(TestVoitureConstructor, Default)
{
    Voiture voiture;

    EXPECT_EQ(voiture.kilometrage(), 0);
    EXPECT_EQ(voiture.jaugeCarburant(), 0);
    EXPECT_EQ(voiture.modele(), "");
    //ASSERT_THAT(0, Eq(0));
}

TEST(TestVoitureConstructor, Occasion)
{
    //given
    int kilometrage=160000;
    int jaugeCarburant=5300;
    QString Modele="Ferrari F40";
    //when

    Voiture voiture(Modele,kilometrage,jaugeCarburant);

    EXPECT_EQ(voiture.kilometrage(), kilometrage);
    EXPECT_EQ(voiture.jaugeCarburant(), jaugeCarburant);
    EXPECT_EQ(voiture.modele(), Modele);
        //ASSERT_THAT(0, Eq(0));
}
