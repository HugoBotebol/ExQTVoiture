#include "voiture.h"

Voiture::Voiture():Voiture("",0,0)
{

}

Voiture::Voiture(QString modele):Voiture (modele,0,0)
{
}

Voiture::Voiture(QString modele, int kilometrage, int jaugeCarburant):
    mModele (modele), mKilometrage (kilometrage), mJaugeCarburant (jaugeCarburant)
{
}

Voiture::~Voiture()
{

}

QString Voiture::modele() const
{
    return mModele;
}

void Voiture::setModele(const QString &modele)
{
    mModele = modele;
}

int Voiture::kilometrage() const
{
    return mKilometrage;
}

void Voiture::setKilometrage(int kilometrage)
{
    mKilometrage = kilometrage;
}

int Voiture::jaugeCarburant() const
{
    return mJaugeCarburant;
}

void Voiture::setJaugeCarburant(int jaugeCarburant)
{
    mJaugeCarburant = jaugeCarburant;
}

void Voiture::rouler(int km)
{
    int conso = 500;
    if (kilometrage() > 150000)
        {conso= 1000;}

    int consomation = (km/100)*conso;
    if (consomation > mJaugeCarburant)
    {
        throw std::invalid_argument("Pas assez d'essence");
    }

    else
        {
          this->setJaugeCarburant(mJaugeCarburant - consomation);
          this->setKilometrage(mKilometrage+km);
        }


}
