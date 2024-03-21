//
// Created by Alexuta on 11.05.2023.
//

#ifndef SEM5SD_LIST_H
#define SEM5SD_LIST_H

#include "node.h"
#include <iostream>
using namespace std;

template <class T>
class List {
private:
    Node<T>* first;
    Node<T>* last;

public:
    /// constructor implicit
    List () {
        this->first=nullptr;
    }

    /// \return dimensiunea listei
    int size() const;

    ///  verifica daca lista e vida
    /// \return true, daca lista e vida, altfel returneaza false
    bool is_empty() const;

    /// adaugare element la sfarsit
    /// \param e - elementul adaugat
    void push_back(T e);

    /// adaugare element la sfarsit
    /// \param e - elementul adaugat
    void push_front(T e);

    ///
    /// \param i - pozitia unui elem in lista , 0<=i<size()
    /// \return  elementul de pe pozitia i
    T get_at(int i) const;

    /// modifica element de pe pozitia i si returneaza vechea valoare
    T update(int i, T e);

    /// adaugare element pe o pozitie i
    void set_at(int i, T e);

    /// sterge element de pe o pozitie i si returneaza elementul sters
    T delete_at(int i);

    /// cauta element si returneaza prima pozitie pe care apare (sau -1)
    int search(T e)  const;

    ///returneaza adresa primului element din lista
    Node<T>* getFirst();

    ///returneaza adresa ultimului element din lista
    Node<T>* getLast();
    ///
    /// destructor
    void Destructor();

};

template<class T>
void List<T>::Destructor() {
    while(first != nullptr){
        Node<T>* node = first->next;
        delete first;
        first = node;
    }
}

template<class T>
Node<T> *List<T>::getLast() {
    return last;
}

template<class T>
Node<T> *List<T>::getFirst() {
    return first;
}

template<class T>
void List<T>::push_front(T e) {
    Node<T>* newNode = new Node<T>(nullptr, e, first);
    first = newNode;
    if(size() == 1)
        last = newNode;
}

template<class T>
T List<T>::update(int i, T e)
{
    Node<T>* crt = first;
    int noE = 0;
    while (noE < i){
        crt = crt->next;
        noE++;
    }
    T old_value = crt->info;
    crt->info = e;
    return old_value;
}

template<class T>
T List<T>::get_at(int i) const
{
    Node<T>* crt = first;
    int noE = 0;
    while (noE < i){
        crt = crt->next;
        noE++;
    }
    return crt->info;
}

template<class T>
T List<T>::delete_at(int i)
{
    if(i == 0){
        Node<T>* node = first->next;
        T val = first->getInfo();
        delete first;
        first = node;
        first->previous = nullptr;
        return val;
    }
    else
    if(size()-1 == i){
        Node<T>* node = last->previous;
        T val = last->getInfo();
        delete last;
        last = node;
        last->next = nullptr;
        return val;
    }
    else{
        Node<T>* crt = this->first;
        Node<T>*  aux;
        int noE = 0;
        while(noE <= i-1)
        {
            crt = crt->next;
            noE++;
        }
        aux = crt;
        T e = aux->getInfo();
        (aux->previous)->next = aux->next;
        delete aux;
        return e;
    }

}

template<class T>
void List<T>::push_back(T e)
{
    Node<T>* newNode = new Node<T>(nullptr, e, nullptr);
    if(first == nullptr){
        first = newNode;
    }
    else{
        Node<T>* last1=first;
        while (last1->next != nullptr){
            last1= last1->next;
        }
        last1->next = newNode;
        newNode->previous = last1;
        last = newNode;
    }
}

template<class T>
bool List<T>::is_empty() const
{
    return first == nullptr;
}

template<class T>
int List<T>::size() const
{
    int contor = 0;
    Node<T>* last = first;
    while(last != nullptr)
    {
        contor++;
        last = last->next;
    }
    return contor;
}

template<class T>
int List<T>::search(T e) const
{
    int contor = 0;
    if(this->first == nullptr)
        return -1;
    Node<T>* crt = this->first;
    while(crt!= nullptr)
    {
        if(crt->info == e)
            return contor;
        contor++;
        crt = crt->next;
    }
    return -1;
}

template<class T>
void List<T>::set_at(int i, T e)
{
    Node<T>* newNode = new Node<T>(nullptr, e, nullptr);
    if(i == 0){
        push_front(e);
    }
    else
    if(i == size()){
        push_back(e);
    }
    else{
        Node<T>* crt = first;
        int contor = 0;
        while (contor<i-1)
        {
            contor++;
            crt = crt->next;
        }
        newNode->next = crt->next;
        newNode->previous = crt;
        crt->next = newNode;
    }
}

#endif //SEM5SD_LIST_H
