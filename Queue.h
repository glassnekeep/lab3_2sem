//
// Created by - on 18.05.2022.
//

#ifndef LAB2_2SEM_QUEUE_H
#define LAB2_2SEM_QUEUE_H

#include "Sequence.h"

template <class T>
class Queue{
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
        for (int i = 0; i< que.Size();i++)
        {
            internalListSequence->Append(que.Peek(i));
        }
    }
    // Деструктор
    ~Queue() {
        delete internalListSequence;
    }
    // добавить элемент в очередь
    void push(const T& data) {
        internalListSequence->Append(data);
    }
    //pol вместо pop по соглашению
    // удалить элемент из начала очереди
    T pop() {
        T result = internalListSequence->GetFirst();
        internalListSequence = (LinkedListSequence<T>*)internalListSequence->GetSubsequence(1, internalListSequence->GetLength() - 1);
        return result;
    }
    // TODO: Если будет сложно состовной тип класс, то в нём описываем перегрузку оператора стрелочки <<
    // вывод очереди
    void printQueue() {
        for (int i = 0; i < internalListSequence->GetLength();i++) {
            cout <<i<<".  "<<internalListSequence->Get(i)<< endl;
        }
    }
    // n-й элемент от вершины очереди
    T Peek(int index) {
        return internalListSequence->Get(index);
    }
    // получить размер очереди
    int Size() {
        return internalListSequence->GetLength();
    }
    // пуста ли очередь
    bool isEmpty() {
        return (internalListSequence->GetLength() < 1)? true : false;
    }
    void map(T mupFunc(T arg)) {
        internalListSequence -> map(mupFunc);
    }
    void where(bool(*whereFunc)(T)) {
        LinkedListSequence<T>* buf = internalListSequence;
        internalListSequence = internalListSequence->wwhere(whereFunc);
        delete buf;
    }
    Queue<T>* Concat(Queue<T>& que2) {
        internalListSequence->Concat(que2.internalListSequence);
        return this;
    }
    Queue<T>* GetSubsequence(int startIndex, int endIndex) {
        Queue<T>* bufQue = new Queue<T>;
        bufQue->internalListSequence = internalListSequence->GetSubsequence(startIndex, endIndex);
        return bufQue;
    }
    bool SubSequenceSearch(Queue<T>& que) {
        return internalListSequence->SubSequenceSearch(que.internalListSequence);
    }
};

#endif //LAB2_2SEM_QUEUE_H
