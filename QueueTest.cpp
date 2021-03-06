//Queue
// Created by - on 19.05.2022.
//

#include "QueueTest.h"
#include "Queue.h"
#include "LinkedListSequence.h"

using namespace std;

void queueAppendTest() {
    int items[2] = {23, 12};
    int finalItems[3] = {23, 12, 42};
    auto* queue = new Queue<int>(items, 2);
    queue -> append(42);
    auto* finalQueue = new Queue<int>(finalItems, 3);
    for (int i = 0; i < 3; i++) {
        assert(queue -> get(i) == finalQueue -> get(i));
    }
}

void queuePrependTest() {
    int items[2] = {23, 12};
    int finalItems[3] = {42, 23, 12};
    auto* queue = new Queue<int>(items, 2);
    queue -> prepend(42);
    auto* finalQueue = new Queue<int>(finalItems, 3);
    for (int i = 0; i < 3; i++) {
        assert(queue -> get(i) == finalQueue -> get(i));
    }
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
    auto* queue1 = new Queue<int>(items, 5);
    int popValue = queue -> pop();
    for (int i = 0; i < 4; i++) {
        assert(queue -> get(i) == queue1 -> get(i + 1));
    }
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

void concatTest() {
    int items1[3] = {23, 12, 43};
    int items2[2] = {54, 73};
    int items3[5] = {23, 12, 43, 54, 73};
    auto* queue1 = new Queue<int>(items1, 3);
    auto* queue2 = new Queue<int>(items2, 2);
    auto* queue3 = new Queue<int>(items3, 5);
    queue1 -> concat(*queue2);
    for (int i = 0; i < 5; i++) {
        assert(queue1 -> get(i) == queue3 -> get(i));
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
    concatTest();
    cout << "Queue tests passed successfully";
}


#include "QueueTest.h"
