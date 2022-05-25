//
// Created by - on 19.05.2022.
//

#ifndef LAB3_2SEM_QUEUEARRAY_H
#define LAB3_2SEM_QUEUEARRAY_H

#include "ArraySequence.h"

template <class T>
class QueueArray {
private:
    ArraySequence<T>* array;
public:
    QueueArray() {
        array = new ArraySequence<T>();
    }
    //Конструктор копирования
    QueueArray(QueueArray<T>& que) {
        array = new ArraySequence<T>();
        for (int i = 0; i < que.getSize();i++) {
            array -> append(que.peek(i));
        }
    }
    // Деструктор
    ~QueueArray() {
        delete array;
    }
    // добавить элемент в очередь
    void push(const T& data) {
        array -> append(data);
    }
    //pol вместо pop по соглашению
    // удалить элемент из начала очереди
    T pop() {
        T result = array -> getFirst();
        array = (ArraySequence<T>*)array -> getSubsequence(1, array -> getLength() - 1);
        return result;
    }
    // TODO: Если будет сложно состовной тип класс, то в нём описываем перегрузку оператора стрелочки <<
    // вывод очереди
    void printQueue() {
        for (int i = 0; i < array -> getLength(); i++) {
            cout <<i<<".  " << array-> get(i) << endl;
        }
    }
    // n-й элемент от вершины очереди
    T peek(int index) {
        return array -> get(index);
    }
    // получить размер очереди
    int getSize() {
        return array -> getLength();
    }
    // пуста ли очередь
    bool isEmpty() {
        return (array -> getLength() < 1);
    }
    void map(T mupFunc(T arg)) {
        array -> map(mupFunc);
    }
    void where(bool(*whereFunc)(T)) {
        ArraySequence<T>* buf = array;
        array = array -> where(whereFunc);
        delete buf;
    }
    QueueArray<T>* concat(QueueArray<T>& que2) {
        array -> concat(que2.array);
        return this;
    }
    QueueArray<T>* getSubsequence(int startIndex, int endIndex) {
        auto* bufQue = new QueueArray<T>;
        bufQue -> array = array -> getSubsequence(startIndex, endIndex);
        return bufQue;
    }
    bool subSequence(QueueArray<T>& queue) {
        return array -> subSequence(queue.internalListSequence);
    }
};

template <typename T>
ostream & operator << (ostream & out, QueueArray<T>* queueArray) {
    for (int i = 0; i < queueArray -> getSize(); i++) {
        out << queueArray -> get(i) << " ";
    }
    return out;
}

#endif //LAB3_2SEM_QUEUEARRAY_H
