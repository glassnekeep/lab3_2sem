//
// Created by - on 05.05.2022.
//

#include "ArraySequenceTest.h"
#include "LinkedListTest.h"
#include "DynamicArrayTest.h"
#include "LinkedListSequenceTest.h"
#include "QueueTest.h"
using namespace std;

int main() {
    arraySequenceTests();
    cout << endl;
    dynamicArrayTest();
    cout << endl;
    linkedListTest();
    cout << endl;
    listSequenceTest();
    cout << endl;
    queueTest();
}