#include <QCoreApplication>
#include <QDebug>
#include "voiture.h"

int main(int argc, char *argv[])
{
   
   //new comment
    QCoreApplication a(argc, argv);
    qDebug()<< "Bienvenu dans VoitureAppli !"<<endl;
    Voiture oldCar("Ford Mustang 1967", 160000,500);
    oldCar.rouler(50);
    qDebug() << "My car: " << oldCar.modele() << endl;

    return a.exec();
}
