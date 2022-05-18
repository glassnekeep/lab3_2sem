//
// Created by - on 05.05.2022.
//

#include "LinkedListSequenceTest.h"

using namespace std;

void listSequenceFromArrayTest() {
    int items[5] = {123, 312, 412, 45, 12};
    auto* seq = new LinkedListSequence(items,5);
    for (int i = 0; i < 5; i++) {
        assert((*seq)[i] == items[i]);
    }
}
void listSequenceFromListTest() {
    int items[5] = {123, 312, 412, 45, 12};
    auto* list1 = new LinkedList<int>(items,5);
    auto* second = new LinkedListSequence<int>(*list1);
    for (int i = 0; i < 5; i++) {
        assert((*list1)[i] == (*second)[i]);
    }
}

void listSequencePrependTest() {
    int items[5] = {123, 312, 412, 45, 12};
    auto *seq = new LinkedListSequence<int>(items,5);
    seq -> prepend(42);
    assert(seq -> get(0) == 42);
}
void listSequenceAppendTest() {
    int items[5] = {123, 312, 412, 45, 12};
    auto *seq = new LinkedListSequence<int>(items,5);
    seq -> append(42);
    assert(seq -> get(5) == 42);
}
void listSequenceInsertAtTest() {
    int items[5] = {123, 312, 412, 45, 12};
    auto *seq = new LinkedListSequence<int>(items,5);
    seq -> insertAt(52,2);
    assert(seq -> get(2) == 52);
}

void listSequenceGetSubSeqTest() {
    int items[5]={123, 312, 412, 45, 12};
    auto *list1=new LinkedListSequence<int>(items,5);
    Sequence <int> *list2=list1 -> getSubsequence(1,3);
    for (int i=0;i<3;i++) {
        assert((*list1)[i + 1] == (*list2)[i]);
    }
}
void listSequenceConcatTests() {
    int items[5]={123, 312, 412, 45, 12};
    auto* list= new LinkedListSequence<int>(items,5);
    Sequence<int>* second = new LinkedListSequence <int>();
    second=second -> concat(list);
}
void listSequenceTest() {
    listSequenceFromArrayTest();
    listSequenceFromListTest();
    listSequencePrependTest();
    listSequenceAppendTest();
    listSequenceInsertAtTest();
    listSequenceGetSubSeqTest();
    listSequenceConcatTests();
    cout<<"LinkedListSequence tests successfully passed";
}


