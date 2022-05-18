//
// Created by - on 05.05.2022.
//

#include "ArraySequenceTest.h"
using namespace std;

void arraySequenceFromArrayTest() {
    int items[5] = {123, 312, 412, 45, 12};
    auto* array = new ArraySequence(items,5);
    for (int i = 0; i < 5; i++) {
        assert((*array)[i] == items[i]);
    }
}
void arraySequenceFromDynamicArrayTest() {
    int items[5] = {123, 312, 412, 45, 12};
    auto *array = new DynamicArray<int>(items, 5);
    auto *second = new ArraySequence<int>(*array);

    for (int i = 0; i < 4; i++) {
        assert((*array)[i] == (*second)[i]);
    }
}
void arraySequencePrependTest() {
    int items[5] = {123, 312, 412, 45, 12};
    auto *array = new ArraySequence<int>(items,5);
    array -> prepend(42);
    assert(array -> get(0) == 42);
}
void arraySequenceAppendTest() {
    int items[5] = {123, 312, 412, 45, 12};
    auto *array = new ArraySequence<int>(items,5);
    array -> append(42);
    assert(array -> get(5) == 42);
}
void arraySequenceInsertAtTest() {
    int items[5] = {123, 312, 412, 45, 12};
    auto *array = new ArraySequence<int>(items,5);
    array -> insertAt(52,2);
    assert(array -> get(2)==52);
}
void arraySequenceGetSubSeqTest() {
    int items[5] = {123, 312, 412, 45, 12};
    auto *array1 = new ArraySequence<int>(items,5);
    Sequence <int> *array2=array1 -> getSubsequence(1,3);
    for (int i = 0; i < 3; i++) {
        assert((*array1)[i+1] == (*array2)[i]);
    }
}
void arraySequenceConcatTests() {
    int items[5] = {123, 312, 412, 45, 12};
    auto* array = new ArraySequence<int>(items,5);
    Sequence<int>* second = new ArraySequence <int>();
    second = second -> concat(array);
    for (int i = 0; i < 5; i++) {
        assert((*array)[i] == (*second)[i]);
    }
}
void arraySequenceTests() {
    arraySequenceFromArrayTest();
    arraySequenceFromDynamicArrayTest();
    arraySequencePrependTest();
    arraySequenceAppendTest();
    arraySequenceInsertAtTest();
    arraySequenceGetSubSeqTest();
    arraySequenceConcatTests();
    cout << "ArraySequence tests successfully passed";
}
