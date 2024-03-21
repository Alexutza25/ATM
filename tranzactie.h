//
// Created by Alexuta on 28.03.2023.
//

#ifndef SDSEM2_TRANZACTIE_H
#define SDSEM2_TRANZACTIE_H
#include "colectie.h"
#include<iostream>
#include<string>
using namespace std;

typedef int TElem;

class Tranzactie {
private:
    int Id_tranzatie;
    int suma;
    Element* bancnote;
    int nr_banconte;
public:
    Tranzactie(int id, int suma, Element bancnote[], int nr_bancnote);   //Constructor cu parametrii
    Tranzactie();                                                        //Constructor implicit
    void Destructor();                                                   //Destructor
    int getId();
    int getSuma();
    Element* getBancnote();
    int getNrAp();
    void setId(int indice);
    void setSuma(int suma);
    void setBancnote(Element *bancnote);
    void setNrAp(int nrAp);
    friend ostream& operator<<(ostream& os, Tranzactie tranzactie);      //Supra incarcare operator afisare
    Tranzactie& operator==(const Tranzactie& tranzactie);                 //operator de atribuire
    string ToString();
};

#endif //SDSEM2_TRANZACTIE_H
