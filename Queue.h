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
    // Конструкторы
    Queue() {
        internalListSequence = new LinkedListSequence<T>();
    }
    //Конструктор копирования
    Queue(Queue<T>& que) {
        internalListSequence = new LinkedListSequence<T>();
        for (int i = 0; i< que.getSize();i++) {
            internalListSequence -> append(que.peek(i));
        }
    }
    // Деструктор
    ~Queue() {
        delete internalListSequence;
    }
    // добавить элемент в очередь
    void push(const T& data) {
        internalListSequence -> append(data);
    }
    //pol вместо pop по соглашению
    // удалить элемент из начала очереди
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
        auto* bufQue = new Queue<T>;
        bufQue -> internalListSequence = internalListSequence -> getSubsequence(startIndex, endIndex);
        return bufQue;
    }
    bool subSequence(Queue<T>& queue) {
        return internalListSequence -> subSequence(queue.internalListSequence);
    }

    ostream & operator << (ostream & out, Queue<T> a) {
        try {
            for (int i = 0; i < queue.getSize(), ++i) {
                out << queue.get(i) << " ";
            }
            return out;
        } catch (Exception &exception) {
            throw exception;
        }
    }
};

#endif //LAB2_2SEM_QUEUE_H
