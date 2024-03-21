//
// Created by Alexuta 28.03.2023.
//

#ifndef SDSEM2_ATM_H
#define SDSEM2_ATM_H
#include "tranzactie.h"
#include "colectie.h"
#include<iostream>
#include<string>
using namespace std;

class ATM {
private:
    Collection colectie_bancnote;
    Tranzactie* tranzactii;
    int nr_tranzactii;
    void afisare_colectie(Element bancnote[], int lungime, int k);
    string filename;
public:
    ATM(string fileBancnote,const Collection& colectie, Tranzactie tranzactie[], int nr_tranzactii);
    ATM(const Collection& colectie, Tranzactie tranzactie[], int nr_tranzactii);
    void Retragere_numerar(int id, int suma, int lungime, Element bancnote[]);
    friend ostream& operator<<(ostream& os, ATM atm);
    void Add_bancnote(TElem valoare);
    void Elim_bancnota(TElem valoare);
    void Get_tranzactia(int& poz_stop,int suma, Element bancnote[], int lungime, int poz);
    void Generare_Tranzactii(int& indice,int suma, Element bancnote[], int lungime, int poz);
    void Destructor();

};

#endif //SDSEM2_ATM_H
