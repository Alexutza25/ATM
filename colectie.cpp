#include "colectie.h"

#include<iostream>
using namespace std;
typedef int TElem;

Collection::Collection() {
    this->distinctelements = 0;
    this->capacity = 10;
}

void Collection::add(TElem elem) {
    if(search(elem)){
        int ok = 1;
        for(int i = 0; i< this->distinctelements&&ok; i++)
            if(elements.get_at(i).valoare == elem){
                int nrAparitii = this->elements.get_at(i).nr_aparitii +1;
                Element elem2;
                elem2.valoare = elem;
                elem2.nr_aparitii = nrAparitii;
                this->elements.update(i,elem2);
                ok =0;
            }
    }
    else{
        if(this->distinctelements == capacity)
            redim();
        Element elem2;
        elem2.valoare = elem;
        elem2.nr_aparitii = 1;
        this->elements.push_back(elem2);
        this->distinctelements++;
    }
}

bool Collection::remove(TElem elem) {
    if(search(elem))
    {
        int i = 0;
        while(this->elements.get_at(i).valoare != elem)
            i++;
        for(int j = i; j< this->distinctelements - 1;j++){
            this->elements.update(j,this->elements.get_at(j+1));
        }
        this->distinctelements --;
        return true;
    }
    return false;
}

bool Collection::search(TElem elem) {
    for(int i = 0; i< this->distinctelements; i++)
        if(this->elements.get_at(i).valoare == elem)
            return true;
    return false;
}

int Collection::size() {
    int sum = 0;
    for(int i = 0; i< this->distinctelements; i++)
        sum = sum + this->elements.get_at(i).valoare* this->elements.get_at(i).nr_aparitii;
    return sum;
}

int Collection::nroccurrences(TElem elem) {
    if(search(elem)){
        int i = 0;
        while(this->elements.get_at(i).valoare != elem)
            i++;
        return this->elements.get_at(i).nr_aparitii;
    }
    return -1;
}

void Collection::Destructor() {
    this->capacity = 0;
    this->distinctelements = 0;
    Destructor();
}

int Collection::getAt(int position) {
    return this->elements.get_at(position).nr_aparitii;
}

void Collection::Collection::redim() {
    this->capacity = this->capacity*2;
}

int Collection::get_lungime() {
    return this->distinctelements;
}

TElem Collection::get_val(int position) {
    return this->elements.get_at(position).valoare;
}

Collection &Collection::operator=(const Collection &colectie) {
    if(colectie.distinctelements!=0){
        this->distinctelements = colectie.distinctelements;
        this->capacity = colectie.capacity;
        for(int i = 0;i<this->capacity;i++)
            this->elements.update(i,colectie.elements.get_at(i));
        return *this;
    }
    return *this;

}

void Collection::set_numar_bancnote(Element elem) {
    if(search(elem.valoare))
    {
        int i = 0;
        while(this->elements.get_at(i).valoare != elem.valoare)
            i++;
        this->elements.update(i,elem);
    }
}