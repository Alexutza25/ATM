//
// Created by Alexuta on 28.05.2023.
//

#ifndef SDSEM2_NODE_H
#define SDSEM2_NODE_H


template <typename T>
class List;

template <class T>
class Node {
private:
    Node<T>* previous;
    T info;
    Node<T>* next;
public:
    Node( Node<T>* back, T info, Node<T>* next) : info(info), next(next), previous(back){}
    Node(T info) : info(info){ next= nullptr, previous = nullptr;}
    T getInfo();
    friend class List<T>;
};

template<class T>
T Node<T>::getInfo() {
    return info;
}

#endif //SDSEM2_NODE_H
