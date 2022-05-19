//
// Created by - on 19.05.2022.
//

#include "QueueTest.h"
#include "Queue.h"
#include "LinkedListSequence.h"

using namespace std;

void queueAppendTest() {
    int items[5] = {23, 12, 43, 54, 66};
    auto* queue = new Queue<int>(items, 4);
    queue -> append(42);
    assert(queue -> get(5) == 42);
}

void queuePrependTest() {
    int items[5] = {23, 12, 43, 54, 66};
    auto* queue = new Queue<int>(items, 4);
    queue -> prepend(42);
    assert(queue -> get(0) == 42);
}

void queueSubSequenceTest() {
    int items[4] = {23, 12, 43, 54};
    auto* queue = new Queue<int>(items, 4);
    Queue<int> *subQueue = queue -> getSubsequence(1, 3);
    for (int i = 0; i < 3; i++) {
        assert(((*queue).get(i + 1) == (*subQueue).get(i)))
    }
}

#include "QueueTest.h"
