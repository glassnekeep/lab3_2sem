//
// Created by - on 19.05.2022.
//

#ifndef LAB3_2SEM_QUEUEARRAY_H
#define LAB3_2SEM_QUEUEARRAY_H

#include "ArraySequence.h"

template <class T>
class QueueArray {
private:
    ArraySequence<T>* internalArray; // указатель на связный список
public:
    T& operator[](int index);
    // Конструкторы
    QueueArray() {
        internalArray = new ArraySequence<T>();
    }
    //Конструктор копирования
    QueueArray(QueueArray& que) {
        internalArray = new ArraySequence<T>(*que.internalArray);
    }
    QueueArray(T* items, int count) {
        internalArray = new ArraySequence(items, count);
    }
    explicit QueueArray(const ArraySequence<T>& list) {
        internalArray = new ArraySequence<T>(list);
    }
    // Деструктор
    ~QueueArray() {
        delete internalArray;
    }
    T get(int index) {
        try {
            T result = internalArray -> get(index);
            return result;
        } catch (Exception& exception) {
            throw exception;
        }
    }
    // добавить элемент в очередь
    void push(const T& data) {
        internalArray -> append(data);
    }
    T pop() {
        T result = internalArray -> getFirst();
        internalArray = (ArraySequence<T>*)internalArray -> getSubsequence(1, internalArray->getLength() - 1);
        return result;
    }
    // TODO: Если будет сложно состовной тип класс, то в нём описываем перегрузку оператора стрелочки <<
    // вывод очереди
    void printQueue() {
        for (int i = 0; i < internalArray -> getLength(); i++) {
            cout <<i<<".  "<< internalArray -> get(i) << endl;
        }
    }
    // n-й элемент от вершины очереди
    T peek(int index) {
        return internalArray -> get(index);
    }
    // получить размер очереди
    int getSize() {
        return internalArray -> getLength();
    }
    void append(T item) {
        internalArray -> append(item);
    }
    void prepend(T item) {
        internalArray -> prepend(item);
    }
    // пуста ли очередь
    bool isEmpty() {
        return (internalArray -> getLength() < 1);
    }
    void map(T mupFunc(T arg)) {
        int size = internalArray -> getLength();
        internalArray -> map(mupFunc);
    }
    void where(bool(*whereFunc)(T)) {
        ArraySequence<T>* buf = internalArray;
        internalArray = internalArray -> where(whereFunc);
        delete buf;
    }
    QueueArray<T>* concat(QueueArray<T>& que2) {
        internalArray -> concat(que2.internalArray);
        return this;
    }
    Sequence<T>* getSubsequence(int startIndex, int endIndex) {
        return internalArray -> getSubsequence(startIndex, endIndex);
    }
    bool subSequence(QueueArray<T>& queue) {
        return internalArray -> subSequence(queue.internalArray);
    }
};
template <class T>
T& QueueArray<T>::operator[](int index) {
    if (index > getSize() - 1 || index < 0) {
        throw Exception(1);
    }
    return this -> internalArray[index];
}

template <typename T>
ostream & operator << (ostream & out, Queue<T>* queue) {
    for (int i = 0; i < queue -> getSize(); i++) {
        out << queue -> get(i) << " ";
    }
    return out;
}

#endif //LAB3_2SEM_QUEUEARRAY_H
