//
// Created by - on 18.05.2022.
//

#ifndef LAB2_2SEM_QUEUE_H
#define LAB2_2SEM_QUEUE_H

#include "Sequence.h"
#include "LinkedListSequence.h"
#include "ArraySequence.h"

template <class T>
class Queue {
private:
    LinkedListSequence<T>* internalListSequence; // указатель на связный список
public:
    T& operator[](int index);
    // Конструкторы
    Queue() {
        internalListSequence = new LinkedListSequence<T>();
    }
    //Конструктор копирования
    /*Queue(const Queue<T>& que) {
        internalListSequence = new LinkedListSequence<T>();
        for (int i = 0; i< que.getSize();i++) {
            internalListSequence -> append(que.peek(i));
        }
    }*/
    Queue(T* items, int count) {
        internalListSequence = new LinkedListSequence(items, count);
    }
    Queue(const LinkedListSequence<T>& list) {
        internalListSequence = new LinkedListSequence<T>(list);
    }
    // Деструктор
    ~Queue() {
        delete internalListSequence;
    }
    T get(int index) {
        try {
            T result = internalListSequence -> get(index);
            return result;
        } catch (Exception& exception) {
            throw exception;
        }
    }
    // добавить элемент в очередь
    void push(const T& data) {
        internalListSequence -> append(data);
    }
    T pop() {
        T result = internalListSequence -> getFirst();
        internalListSequence = (LinkedListSequence<T>*)internalListSequence -> getSubsequence(1, internalListSequence->getLength() - 1);
        return result;
    }
    // TODO: Если будет сложно состовной тип класс, то в нём описываем перегрузку оператора стрелочки <<
    // вывод очереди
    void printQueue() {
        for (int i = 0; i < internalListSequence -> getLength(); i++) {
            cout <<i<<".  "<< internalListSequence -> get(i) << endl;
        }
    }
    // n-й элемент от вершины очереди
    T peek(int index) {
        return internalListSequence -> get(index);
    }
    // получить размер очереди
    int getSize() {
        return internalListSequence -> getLength();
    }
    void append(T item) {
        internalListSequence -> append(item);
    }
    void prepend(T item) {
        internalListSequence -> prepend(item);
    }
    // пуста ли очередь
    bool isEmpty() {
        return (internalListSequence -> getLength() < 1);
    }
    void map(T mupFunc(T arg)) {
        int size = internalListSequence -> getLength();
        internalListSequence -> map(mupFunc);
    }
    void where(bool(*whereFunc)(T)) {
        LinkedListSequence<T>* buf = internalListSequence;
        internalListSequence = internalListSequence -> where(whereFunc);
        delete buf;
    }
    Queue<T>* concat(Queue<T>& que2) {
        internalListSequence -> concat(que2.internalListSequence);
        return this;
    }
    Queue<T>* getSubsequence(int startIndex, int endIndex) {
        //this -> internalListSequence -> getSubsequence(startIndex, endIndex);
        return new Queue<T>(internalListSequence -> getSubsequence(startIndex, endIndex));
    }
    bool subSequence(Queue<T>& queue) {
        return internalListSequence -> subSequence(queue.internalListSequence);
    }
};
template <class T>
T& Queue<T>::operator[](int index) {
    if (index > getSize() - 1 || index < 0) {
        throw Exception(1);
    }
    return internalListSequence[index];
}

template <typename T>
ostream & operator << (ostream & out, Queue<T> queue) {
    try {
        for (int i = 0; i < queue.getSize(); ++i) {
            out << queue.get(i) << " ";
        }
        return out;
    } catch (Exception &exception) {
        throw exception;
    }
}

#endif //LAB2_2SEM_QUEUE_H
