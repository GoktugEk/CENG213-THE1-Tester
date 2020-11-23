#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <iostream>

#include "Node.h"

template<class T>
class LinkedList {
public: // DO NOT CHANGE THIS PART.
    LinkedList();
    LinkedList(const T arr[], int arrSize);
    LinkedList(const LinkedList<T> &obj);

    ~LinkedList();

    Node<T> *getFirstNode() const;
    Node<T> *getLastNode() const;
    Node<T> *getNode(const T &data) const;

    int getNumberOfNodes() const;
    bool isEmpty() const;
    bool contains(Node<T> *node) const;

    void insertAtTheHead(const T &data);
    void insertAtTheTail(const T &data);
    void insertSorted(const T &data);

    void removeNode(Node<T> *node);
    void removeNode(const T &data);
    void removeAllNodes();

    void print() const;

    T *toArray() const;

    LinkedList<T> &operator=(const LinkedList<T> &rhs);

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.
    void insertNode(const T data, Node<T>* prev, Node<T>* next);
private: // DO NOT CHANGE THIS PART.
    Node<T> *head;
    Node<T> *tail;
};

template<class T>
LinkedList<T>::LinkedList() {
    this->head = NULL;
    this->tail = NULL;
}

template<class T>
LinkedList<T>::LinkedList(const T arr[], int arrSize){
    this->head = NULL;
    this->tail = NULL;

    for (int i = 0; i < arrSize; i++)
    {
        this->insertAtTheTail(arr[i]);
    }
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &obj) {
    Node<T> *current;
    
    
    this->head = NULL;
    this->tail = NULL;


    if(obj.isEmpty()){
        return;
    }
    
    current = obj.head;

    while (current != NULL)
    {

        this->insertAtTheTail(current->data);

        current = current->next;
    }



}

template<class T>
void LinkedList<T>::insertNode(const T data, Node<T>* prev, Node<T>* next){
    Node<T> *newnode;

    newnode = new Node<T>(data, prev, next);

    prev->next = newnode;
    next->prev = newnode;

}




template<class T>
LinkedList<T>::~LinkedList() {
    this->removeAllNodes();
}

template<class T>
Node<T> *LinkedList<T>::getFirstNode() const {
    return this->head;
}

template<class T>
Node<T> *LinkedList<T>::getLastNode() const {
    return this->tail;
}

template<class T>
Node<T> *LinkedList<T>::getNode(const T &data) const {
    Node<T>* current;

    if (this->isEmpty()) return NULL;

    current = this->head;

    while (current != NULL)
    {
        if (current->data == data)
        {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

template<class T>
int LinkedList<T>::getNumberOfNodes() const {
    Node<T>* current;
    current = this->head;

    int num = 0;

    while (current != NULL)
    {
        num++;

        current = current->next;
    }

    return num;
}

template<class T>
bool LinkedList<T>::isEmpty() const {
    return (NULL == this->head);
}

template<class T>
bool LinkedList<T>::contains(Node<T> *node) const {
    Node<T> *current;
    current = this->head;

    while (current != NULL)
    {
        if (current == node)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

template<class T>
void LinkedList<T>::insertAtTheHead(const T &data) {
    Node<T> *newnode;
    newnode = new Node<T>(data, NULL, this->head);


    if(this->isEmpty()){
        this->tail       = newnode;
        newnode->next = NULL;
    }
    else{
        this->head->prev = newnode;
        
    }
    
    this->head = newnode;
}

template<class T>
void LinkedList<T>::insertAtTheTail(const T &data) {
    if(this->isEmpty()){
        this->insertAtTheHead(data);
    }
    else {
        Node<T> *newnode;
        newnode = new Node<T>(data, this->tail, NULL);
        this->tail->next = newnode;
        newnode->prev = this->tail;
        this->tail = newnode;

    }
}

template<class T>
void LinkedList<T>::insertSorted(const T &data) {
    Node<T> *current;
    current = this->head;
    if (this->isEmpty()){
        this->insertAtTheHead(data);
    }
    else if (data > this->tail->data)
    {
        this->insertAtTheTail(data);
    }
    else if (data < this->head->data)
    {
        this->insertAtTheHead(data);
    }
    else
    {
        while (current != NULL)
        {
            if (current->data > data )
            {
                this->insertNode(data, current->prev, current);
                return;
            }
            current = current->next;
        }
    }

}

template<class T>
void LinkedList<T>::removeNode(Node<T> *node) {
    Node<T> *current, *extra;
    current = this->head;

    if (this->isEmpty()){}
    else if (this->head == this->tail){
        delete this->head;
        this->head = NULL;
        this->tail = NULL;
    }
    else if(this->head == node){
        this->head = this->head->next;
        delete this->head->prev;
        this->head->prev = NULL;
    }
    else if (this->tail == node){
        this->tail = this->tail->prev;
        delete this->tail->next;
        this->tail->next = NULL;
    }
    else{
        while (current != NULL){
            if(current == node){
                extra = current;
                current->prev->next = current->next;
                current->next->prev = current->prev;
                current = current->next;
                delete extra;
                return;
            }
            current = current->next;
        }
    }
}

template<class T>
void LinkedList<T>::removeNode(const T &data) {
    Node<T> *current, *extra;
    current = this->head;

    if (this->isEmpty()){}
    else if (this->head == this->tail && this->head->data == data){
        delete this->head;
        this->head = NULL;
        this->tail = NULL;
    }
    else if(this->head->data == data){
        this->head = this->head->next;
        delete this->head->prev;
        this->head->prev = NULL;
    }
    else if (this->tail->data == data){
        this->tail = this->tail->prev;
        delete this->tail->next;
        this->tail->next = NULL;
    }
    else{
        while (current != NULL){
            if(current->data == data ){
                extra = current;
                current->prev->next = current->next;
                current->next->prev = current->prev;
                current = current->next;
                delete extra;
                return;
            }
            current = current->next;
        }
    }
        
    }

template<class T>
void LinkedList<T>::removeAllNodes() {

    if(this->isEmpty())
        return;

    while (this->head != this->tail)
    {
        this->head = this->head->next;
        delete this->head->prev;
    }

    delete this->tail;

    this->head = NULL;
    this->tail = NULL;

}

template<class T>
void LinkedList<T>::print() const {
    std::cout << "Printing the linked list ..." << std::endl;

    if (this->isEmpty()) {
        std::cout << "empty" << std::endl;
        return;
    }

    Node<T> *node = this->head;

    while (node) {
        std::cout << *node << std::endl;
        node = node->next;
    }
}

template<class T>
T *LinkedList<T>::toArray() const {
    int size;
    T *arr;
    Node<T> *current;
    current = this->head;
    if (this->isEmpty())
    {
        return NULL;
    }
    else
    {
        size = this->getNumberOfNodes();
        arr = new T[size];

        for (int i = 0; current != NULL; i++, current = current->next)
        {
            arr[i] = current->data;
        }
    }
    return arr;
}

template<class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs) {
    Node<T> *current_2;


    this->removeAllNodes();

    if(rhs.isEmpty()){
        this->head = NULL;
        this->tail = NULL;
        return *this;
    }



    current_2 = rhs.head;

    while (current_2 != NULL)
    {

        this->insertAtTheTail(current_2->data);

        current_2 = current_2->next;


    }
    
    return* this;
}


#endif //LINKEDLIST_H
