//
// Created by - on 05.05.2022.
//

#include "DynamicArrayTest.h"
using namespace std;
void dynamicFromArrayTest() {
    int items[5] = {123, 312, 412, 45, 12};
    auto* array = new DynamicArray(items,5);
    for (int i = 0; i < 5; i++) {
        assert((*array)[i] == items[i]);
    }
}
void dynamicFromDynamicTest() {
    int items[5] = {123, 312, 412, 45, 12};
    auto* array = new DynamicArray<int>(items,5);
    auto* second = new DynamicArray<int>(*array);
    for (int i = 0; i < 5; i++) {
        assert((*array)[i] == (*second)[i]);
    }
}

void dynamicResizeTest() {
    int items[5] = {123, 312, 412, 45, 12};
    auto *array = new DynamicArray<int>(items,5);
    array -> resize(3);
    for (int i = 0; i < 3; i++) {
        assert((*array)[i] == items[i]);
    }
    auto *array2 = new DynamicArray<int>(items,5);
    array2 -> resize(10);
    for (int i = 0; i < 5; i++) {
        assert((*array2)[i] == items[i]);
    }
}


void dynamicPushbackTest() {
    int items[5] = {123, 312, 412, 45, 12};
    auto *array = new DynamicArray<int>(items,5);
    array -> push(42);
    assert(array -> get(5) == 42);
}


void dynamicArrayTest() {
    dynamicFromArrayTest();
    dynamicFromDynamicTest();
    dynamicResizeTest();
    dynamicPushbackTest();
    cout<<"DynamicArray tests successfully passed";
}