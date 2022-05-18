//
// Created by - on 05.05.2022.
//

#include "LinkedListTest.h"

using namespace std;

void listFromArrayTest() {
    int items[5] = {123, 312, 412, 45, 12};
    auto* list1 = new LinkedList(items,5);
    for (int i = 0; i < 5; i++) {
        assert((*list1)[i] == items[i]);
    }
}
void listFromListTest() {
    int items[5] = {123, 312, 412, 45, 12};
    auto* list1 = new LinkedList<int>(items,5);
    auto* second = new LinkedList<int>(*list1);
    for (int i = 0; i < 4; i++) {
        assert((*list1)[i] == (*second)[i]);
    }
}
void listConcatTest() {
    int items[5] = {123, 312, 412, 45, 12};
    auto* list1 = new LinkedList<int>(items,5);
    auto* second = new LinkedList<int>();
    second = second -> concat(*list1);
}

void listPrependTest() {
    int items[5] = {123, 312, 412, 45, 12};
    auto *list1 = new LinkedList<int>(items,5);
    list1 -> prepend(42);
    assert(list1 -> get(0) == 42);
}
void listAppendTest() {
    int items[5] = {123, 312, 412, 45, 12};
    auto *list1 = new LinkedList<int>(items,5);
    list1 -> append(42);
    assert(list1 -> get(5) == 42);
}
void listInsertAtTest() {
    int items[5] = {123, 312, 412, 45, 12};
    auto *list1 = new LinkedList<int>(items,5);
    list1 -> insertAt(2,42);
    assert(list1 -> get(2) == 42);
}

void listDelTest() {
    int items[5] = {123, 312, 412, 45, 12};
    auto *list1 = new LinkedList<int>(items,5);
    list1 -> remove(2);
    for (int i = 0; i < 4; i++) {
        if (i < 2) {
            assert((*list1).get(i) == items[i]);
        } else {
            assert((*list1).get(i) == items[i+1]);
        }
    }
}
void listGetSubListTest() {
    int items[5] = {123, 312, 412, 45, 12};
    auto *list1 = new LinkedList<int>(items,5);
    LinkedList<int> list2 = list1 -> getSubLinkedList(1,3);
    for (int i = 0; i < 3; i++) {
        assert((*list1)[i + 1] == list2[i]);
    }
}
void linkedListTest() {
    listFromArrayTest();
    listFromListTest();
    listConcatTest();
    listPrependTest();
    listAppendTest();
    listInsertAtTest();
    listDelTest();
    listGetSubListTest();
    cout<<"LinkedList tests successfully passed";
}