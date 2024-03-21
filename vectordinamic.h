//
// Created by Alexuta on 11.04.2023.
//

#ifndef SDSEM2_VECTORDINAMIC_H
#define SDSEM2_VECTORDINAMIC_H

#pragma once
#include <iostream>
using namespace std;

template<class TypeData>
class VectorDinamic {
private:
    TypeData* elems;
    int nrElems;
    int capacity;
    void resize();
public:
    VectorDinamic();
    VectorDinamic (int capacitate);
    int size() const;
    TypeData getAt(int i) const;
    TypeData update(int i, TypeData e);
    void push_back(TypeData e);
    void addAt(int i, TypeData e);
    TypeData sterge(int i);
    VectorDinamic& operator=(const VectorDinamic& vec);
    void Destructor();
    ~VectorDinamic();
};

template<class TypeData>
void VectorDinamic<TypeData>::Destructor() {
    delete[] this->elems;
}

template<class TypeData>
VectorDinamic<TypeData>::VectorDinamic() {
    this->nrElems = 0;
    this->capacity = 10;
    this->elems = new TypeData[capacity];
}

template<class TypeData>
VectorDinamic<TypeData> &VectorDinamic<TypeData>::operator=(const VectorDinamic<TypeData> &vec) {
    nrElems = vec.nrElems;
    capacity = vec.capacity;
    delete[] elems;
    elems = new TypeData[capacity];
    for(int i = 0;i<nrElems;i++)
        elems[i] = vec.elems[i];
    return *this;
}

/// Redimenstioneaza vectorul de elemente de tip TypeData
/// \tparam TypeData
template<class TypeData>
void VectorDinamic<TypeData>::resize() {
    this->capacity = this->capacity*2;
    TypeData* aux = new TypeData[this->capacity];
    for(int i = 0;i<this->nrElems; i++)
        aux[i] = elems[i];
    delete[] this->elems;
    this->elems = aux;
}

/// Construieste un vector de elemente de tipul TypeData
/// \tparam TypeData
/// \param capacitate, capacitate>0
/// \raise invalid input exception: daca capacitatea nu are o valoare valida
template<class TypeData>
VectorDinamic<TypeData>::VectorDinamic(int capacitate) {
    this->capacity = capacitate;
    this->elems = new TypeData[capacitate];
    this->nrElems = 0;
}

///
/// \tparam TypeData
/// \return numarul de elemente din vector
template<class TypeData>
int VectorDinamic<TypeData>::size() const {
    return this->nrElems;
}

///
/// \tparam TypeData
/// \param i, 0<= i < numarul de elemente ale vectorului
/// \return elementul aflat pe pozitia i
template<class TypeData>
TypeData VectorDinamic<TypeData>::getAt(int i) const {
    return this->elems[i];
}

/// Actualizeaza elementul de pe pozitia i cu elementul e
/// \tparam TypeData
/// \param i , 0 <= i< numarul de elemente ale vectorului
/// \param e , element de tip TypeData,
/// \return returneaza vechea valoare a elementului aflat pe pozitia i
/// \raise invalid input exception: daca pozitia nu este una valida
template<class TypeData>
TypeData VectorDinamic<TypeData>::update(int i, TypeData e) {
    TypeData aux = elems[i];
    this->elems[i] = e;
    return aux;
}

/// Adauga elementul e la finalul vectorului
/// \tparam TypeData
/// \param e , element de tipul TypeData
template<class TypeData>
void VectorDinamic<TypeData>::push_back(TypeData e) {
    this->elems[nrElems] = e;
    this->nrElems++;
}

/// Adauga pe pozitia i elementul e
/// \tparam TypeData
/// \param i, 0<=i<=numarul de elemente
/// \param e , element de tipul TypeData
/// \raise invalid input exception: daca pozitia i nu este una valida
template<class TypeData>
void VectorDinamic<TypeData>::addAt(int i, TypeData e) {
    if(i == this->nrElems and this->nrElems == this->capacity)
        resize();
    int j = this->nrElems;
    this->nrElems ++;
    while(j>i)
        this->elems[j] = this->elems[j - 1], j--;
    this->elems[i] = e;
}

/// Sterge elementul aflat pe pozitia i
/// \tparam TypeData
/// \param i - pozitia din vacrtor
/// \return elementul care se va sterge
template<class TypeData>
TypeData VectorDinamic<TypeData>::sterge(int i) {
    TypeData aux = this->elems[i];
    this->elems[i] = this->elems[--this->nrElems];
    return aux;
}

/// Deazaloca atributele alocate dinamic
/// \tparam TypeData
template<class TypeData>
VectorDinamic<TypeData>::~VectorDinamic() {

}


#endif //SDSEM2_VECTORDINAMIC_H
