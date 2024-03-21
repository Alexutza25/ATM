//
// Created by Alexuta on 28.03.2023.
//
#include "inout.h"
#include <iostream>
#include "atm.h"
#include <fstream>
using namespace std;

int id=0;

void print_menu(){
    cout<<endl;
    cout<<"1. Afisare bancnote si tranzactii din ATM"<<endl;
    cout<<"2. Adaugare bancnote in ATM"<<endl;
    cout<<"3. Eliminare bancnota din ATM"<<endl;
    cout<<"4. Efectuare Tranzactie"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<endl<<"ALEGETI O OPTIUNE: ";
}

void adauga_bancnote(ATM& atm){
    int i = 1;
    while(i<=10){
        atm.Add_bancnote(200);
        atm.Add_bancnote(100);
        atm.Add_bancnote(50);
        i++;
    }
    i = 1;
    while(i<=30){
        atm.Add_bancnote(20);
        atm.Add_bancnote(10);
        i++;
    }
}


void add_bancnote(ATM& atm) {
    TElem element;
    cout << "Introduceti valoarea bancnotei: ";
    cin >> element;
    cout << "Introduceti numarul de aparitii: ";
    int nr_aparitii;
    cin >> nr_aparitii;
    int i = 1;
    while (i <= nr_aparitii) {
        atm.Add_bancnote(element);
        i++;
    }
}


void elim_bancnota(ATM& atm){
    cout<<"Introduceti bancnota pe care doriti sa o eliminati: ";
    TElem element;
    cin>>element;
    atm.Elim_bancnota(element);
}

void efectuare_tranzactie(ATM &atm){
    int suma, lungime = 0,poz = 0,indice = 0, int_poz = 0;
    Element* bancnote = new Element[100];
    cout<<endl<<"Introduceti suma dorita: ";
    cin>>suma;
    cout<<"Metoda de plata: "<<endl;
    atm.Generare_Tranzactii(indice,suma,bancnote,lungime, poz);

    cout<<"Alegeti 1 pentru confirmare SAU 0 pentru anulare: ";
    cin>>int_poz;
    if(int_poz == 0){
        cout<<"Tranzactie respinsa";
    }
    else{
        atm.Retragere_numerar(id, suma, lungime, bancnote);
    }
    delete[] bancnote;
}

void Menu(){
    int opt = 1;
    Collection colectie;
    int nr_tranzactii=0;
    Tranzactie* tranzactie = new Tranzactie[100];
    ATM atm("G:/Download/LAB5SD/Bancnote.txt",colectie,tranzactie,nr_tranzactii);
    while(opt){
        print_menu();
        cin>>opt;
        switch (opt) {
            case 1:
                cout<<atm;
                break;
            case 2:
                add_bancnote(atm);
                break;
            case 3:
                elim_bancnota(atm);
                break;
            case 4:
                efectuare_tranzactie(atm);
                break;
            default:
                break;
        }
    }
    colectie.Destructor();
    for(int i = 0;i<nr_tranzactii;i++)
        tranzactie[i].Destructor();
}