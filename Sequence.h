//
// Created by - on 27.04.2022.
//

#ifndef LAB2_2SEM_SEQUENCE_H
#define LAB2_2SEM_SEQUENCE_H


//#include "MyComplex.h"
//Темплейт класс какого-то типа T
#include <iostream>
using namespace std;

template <class T> class Sequence {
public:
    // Конструкторы
    Sequence() = default;
    // Декомпозиция
    virtual T getFirst() = 0;	// Возвращает первый элемент
    virtual T getLast() = 0;	// Возвращает последний элемент
    virtual T get(int index) = 0;
    virtual void set(int index, T value) = 0;// Возвращает элемент по индексу
    //GetSubsequence возвращает указатель на подпоследовательность используя
    // индексы начала и конца подпоследовательности из  Sequence
    virtual Sequence<T>* getSubsequence(int startIndex, int endIndex) = 0;
    virtual int getLength() = 0;	// Возвращает длину последовательности
    virtual T& operator[](int index) = 0;

    // Операции
    virtual void append(T item) = 0; // Добавляет элемент в конец списка
    virtual void prepend(T item) = 0; // Добавляет элемент в начало списка
    virtual void insertAt(T item, int index) = 0; // Вставляет элемент в заданную позицию
    virtual Sequence <T>* concat(Sequence <T>* list) = 0; // Сцепляет два списка

    T reduce(T (*reduceFunc)(T &, T &), T startVal);
    void map (T (*maoFunc) (T));
    Sequence* where(bool (*whereFunc)(T));

    // TODO: Много тестов SubSequenceSearch
    bool subSequence(Sequence<T>* seq) {
        bool result = false;
        for (int i = 0; i < getLength() - seq -> getLength(); i++) {
            result = true;
            for (int j = 0; j < seq -> getLength(); j++) {
                result & = (get(i + j) == (seq -> get(j)));
            };
            if (result) break;
        }
        return result;
    }
};

template<class T>
T Sequence<T>::reduce(T (*reduceFunc)(T &, T &), T startVal) {
    T buf = startVal;
    for (int i = 0; i < getLength(); i++) {
        buf = reduceFunc(get(i), buf)
    }
    return buf;
}

template<class T>
void Sequence<T>::map(T (*mapFunc)(T)) {
    for (int i = 0; i < getLength(); i++) {
        set(i, mapFunc(get(i)));
    }
}

template<class T>
Sequence* Sequence<T>::where(bool (*whereFunc)(T)) {
    Sequence<T> *buf = new Sequence<T>();
    for (int i = 0; i < this -> getLength(); i++) {
        if (whereFunc(this -> get(i))) buf -> append(this -> get(i));
    }
    return (Sequence*) buf;
}

template <class T>
std::ostream& operator<<(std::ostream& out, Sequence<T>* seq) {
    for (int i = 0; i < seq -> getLength(); i++)
        out << seq -> get(i) << " ";
    return out;
}


#endif //LAB2_2SEM_SEQUENCE_H
