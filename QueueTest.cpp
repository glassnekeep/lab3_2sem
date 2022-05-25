//Queue
// Created by - on 19.05.2022.
//

#include "QueueTest.h"
#include "Queue.h"
#include "LinkedListSequence.h"

using namespace std;

void queueAppendTest() {
    int items[5] = {23, 12, 43, 54, 66};
    auto* queue = new Queue<int>(items, 5);
    queue -> append(42);
    assert(queue -> get(5) == 42);
}

void queuePrependTest() {
    int items[5] = {23, 12, 43, 54, 66};
    auto* queue = new Queue<int>(items, 5);
    queue -> prepend(42);
    assert(queue -> get(0) == 42);
}

void queueSubSequenceTest() {
    int items[5] = {23, 12, 43, 54, 73};
    Queue<int>* queue = new Queue<int>(items, 5);
    Sequence<int>* sequence = queue -> getSubsequence(1, 3);
    for (int i = 0; i < 3; i++) {
        assert(queue -> get(i + 1) == sequence -> get(i));
    }
}

void pushTest() {
    int items[5] = {23, 12, 43, 54, 73};
    auto* queue = new Queue<int>(items, 5);
    queue -> push(71);
    assert(queue -> get(5) == 71);
}

void popTest() {
    int items[5] = {23, 12, 43, 54, 73};
    auto* queue = new Queue<int>(items, 5);
    int popValue = queue -> pop();
    assert(popValue == 23);
}

void peekTest() {
    int items[5] = {23, 12, 43, 54, 73};
    auto* queue = new Queue<int>(items, 5);
    int peekValue = queue -> peek(0);
    assert(peekValue == 23);
}

template <class T>
T multiplyByTwo(T value) {
    return value * 2;
}

void mapTest() {
    int items[5] = {23, 12, 43, 54, 73};
    auto* queue = new Queue<int>(items, 5);
    auto* oldQueue = new Queue<int>(items, 5);
    oldQueue -> map(multiplyByTwo);
    for (int i = 0; i < 5; i++) {
        assert(queue -> get(i) * 2 == oldQueue -> get(i));
    }
}

void queueTest() {
    queueAppendTest();
    queuePrependTest();
    queueSubSequenceTest();
    mapTest();
    peekTest();
    popTest();
    pushTest();
    cout << "Queue tests passed successfully";
}


#include "QueueTest.h"
