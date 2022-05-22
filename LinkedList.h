//
// Created by - on 04.05.2022.
//

#ifndef LAB2_2SEM_LINKEDLIST_H
#define LAB2_2SEM_LINKEDLIST_H

#include <iostream>
#include "Exception.h"
using namespace std;

template <class T> class LinkedList {
private:
    class Node: LinkedList<T> {
        friend class LinkedList<T>;
    private:
        Node *next;
        T value;
        Node(): next(NULL){};
    };
    Node *head;
    int length;
public:
    LinkedList();
    LinkedList(int size);
    LinkedList(T* items, int size);
    LinkedList(const LinkedList<T>& previousList);

public:
    int getLength() const;
    T get(int index) const;
    void set(int index, T value);
    T getFirst() const;
    T getLast() const;
    LinkedList<T> getSubLinkedList(int fromIndex, int toIndex);

public:
    void append(T data);
    void prepend(T data);
    void insertAt(int index, T data);
    LinkedList<T>* concat(LinkedList<T> previous);
    void remove(int index);
    void clear();
    T& operator[](int index);
};

template <class T>
LinkedList<T>::LinkedList() {
    head = NULL;
    length = 0;
}

template <class T>
LinkedList<T>::LinkedList(int k) {
    head = NULL;
    length = k;
}

template<class T>
LinkedList<T>::LinkedList(T *items, int size) {
    LinkedList<T> linkedList;
    head = NULL;
    length = 0;
    for (int i = 0; i < size; i++) {
        Node *adding = new Node();
        adding -> next = NULL;
        adding -> value = items[i];
        if (head == NULL) {
            head = adding;
        } else {
            Node *current;
            for (current = head; current -> next != NULL; current = current -> next);
            current -> next = adding;
        }
        length++;
    }
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &previousList) {
    Node* newHead = new Node();
    newHead -> value = previousList.head -> value;
    head = newHead;
    length = previousList.getLength();
    for (int i = 1; i < previousList.getLength(); i++) {
        Node *adding = new Node();
        adding -> next = NULL;
        adding -> value = previousList.get(i);
        Node* current;
        for (current = head; current -> next != NULL; current = current -> next);
        current -> next = adding;
    }
}

template<class T>
int LinkedList<T>::getLength() const {
    return length;
}

template<class T>
T LinkedList<T>::get(int index) const {
    if (index < 0 || index > length) {
        throw Exception(1);
    }
    Node* current = head;
    for (int i = 0; index > i; i++) {
        current = current -> next;
    }
    return current -> value;
}

template<class T>
T LinkedList<T>::getFirst() const {
    if (length <= 0) {
        throw Exception(1);
    } else {
        return head -> value;
    }
}

template<class T>
T LinkedList<T>::getLast() const {
    if (length <= 0) {
        throw Exception(1);
    } else {
        return get(length - 1);
    }
}

template<class T>
LinkedList<T> LinkedList<T>::getSubLinkedList(int fromIndex, int toIndex) {
    if (fromIndex < 0 || toIndex > length || toIndex < fromIndex) {
        throw Exception(1);
    }
    try {
        LinkedList sublist = LinkedList();
        sublist.length = 0;
        if (fromIndex < length && toIndex < length) {
            for (int i = fromIndex; i <= toIndex; i++) {
                sublist.append(this -> get(i));
            }
        }
        return sublist;
    } catch (Exception& exception) {
        exception.show();
    }
}

template<class T>
void LinkedList<T>::append(T data) {
    Node* adding = new Node();
    adding -> next = NULL;
    adding -> value = data;
    if (length == 0) {
        head = adding;
    } else {
        Node *current;
        for (current = head; current -> next != NULL; current = current -> next);
        current -> next = adding;
    }
    length++;
}

template<class T>
void LinkedList<T>::prepend(T data) {
    Node* adding = new Node();
    adding -> next = NULL;
    adding -> value = data;
    if (length == 0) {
        head =adding;
    } else {
        adding -> next = head;
        head = adding;
    }
    length++;
}

template<class T>
void LinkedList<T>::insertAt(int index, T data) {
    if (index < 0 || index > length) {
        throw Exception(1);
    }
    if (index == 0) {
        prepend(data);
    } else if (index == length) {
        append(data);
    } else {
        Node* current = head;
        Node* adding = new Node();
        adding -> value = data;
        for (int i = 0; i < index - 1; i++) {
            current = current -> next;
        }
        Node* tmp = current -> next;
        current -> next = adding;
        adding -> next = tmp;
        length++;
    }
}

template<class T>
LinkedList<T> *LinkedList<T>::concat(LinkedList<T> previous) {
    auto* result = new LinkedList();
    *result = *this;
    for (int i = 0; i < previous.getLength(); i++) {
        result -> append(previous[i]);
    }
    return result;
}

template<class T>
void LinkedList<T>::remove(int index) {
    if (index > length || index < 0) {
        throw Exception(1);
    }
    Node* removing = head;
    if (index == 0) {
        head = head -> next;
        delete removing;
    } else {
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current -> next;
        }
        removing = current -> next;
        current -> next = current -> next -> next;
        delete removing;
    }
    length--;
}

template<class T>
void LinkedList<T>::clear() {
    Node* current = head;
    Node* removing = head;
    while (removing != NULL) {
        current = current -> next;
        delete removing;
        removing = current;
    }
    head = NULL;
    length = 0;
}

template<class T>
T& LinkedList<T>::operator[](int index) {
    if (index < 0 || index == length) {
        throw Exception(1);
    } else {
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current -> next;
        }
        return current -> value;
    }
}

template<class T>
void LinkedList<T>::set(int index, T value)  {
    if (index < 0 || index > length) {
        throw Exception(1);
    }
    if (index == 0) {
        prepend(value);
    } else if (index == length) {
        append(value);
    } else {
        Node* current = head;
        Node* adding = new Node();
        adding -> value = value;
        for (int i = 0; i < index - 1; i++) {
            current = current -> next;
        }
        Node* tmp = current -> next;
        current -> next = adding;
        adding -> next = tmp;
        length++;
    }
}


#endif //LAB2_2SEM_LINKEDLIST_H
