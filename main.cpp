#include <iostream>
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include "Queue.h"
#include "QueueArray.h"

using namespace std;

template<class T>
void input(T* value) {
    while (true) {
        cin >> *value;
        break;
    }
}

int multiply(int a) {
    return a * 2;
}

bool isEven(int a) {
    return a % 2;
}

void menu() {
    int data_type = 0;
    cout << "1. int" << endl << "2. double" << endl;
    do {
        input(&data_type);
    } while (data_type != 2 && data_type != 1);
    if (data_type == 1) {
        cout << "1. Queue" << endl << "2. QueueArray" << endl;
        int type = -1;
        do {
            input(&type);
        } while (type != 1 && type != 2);
        Queue<int> *queue;
        QueueArray<int> *seq2;
        if (type == 1) {
            queue = new Queue<int>();
        } else {
            seq2 = new QueueArray<int>();
        }
        //cout << "1. Append" << endl << "2. Prepend" << endl << "3. Get length" << endl << "4. Print" << endl << "0. Exit" << endl;
        cout << "1. Append;\n"
                "2. Prepend;\n"
                "3. Delete element;\n"
                "4. Get size;\n"
                "5. Print;\n"
                "6. Map;\n"
                "7. Where;\n"
                "8. Concat;\n"
                "9. Get subsequence;\n"
                "0. Exit;\n" << endl;
        while (true) {
            type = -1;
            int index;
            while (type < 0 || type > 9) {
                cout << "Choose option" << endl;
                input(&type);
            }
            int item;
            switch (type) {
                case 0:
                    exit(0);
                    break;
                case 1: {
                    cout << "Enter number of elements" <<  endl;
                    int number;
                    input(&number);
                    for (int i = 0; i < number; i++) {
                        cout << "Enter value" << endl;
                        int value;
                        input(&value);
                        queue -> append(value);
                    }
                    break;
                }
                case 2: {
                    cout << "Enter prepend item" << endl;
                    input(&item);
                    queue->prepend(item);
                    break;
                }
                case 3: {
                    /*cout << "Enter deleting item" << endl;
                    input(&item);*/
                    cout << queue -> pop();
                    break;
                }
                case 4: {
                    cout << "The length is: " << queue->getSize() << endl;
                    break;
                }
                case 5: {
                    cout << queue << endl;
                    break;
                }
                case 6: {
                    queue -> map(multiply);
                    cout << queue << endl;
                    break;
                }
                case 7: {
                    //queue -> where(isEven);
                    break;
                }
                case 8: {
                    auto* newQueue = new Queue<int>();
                    cout << "Enter number of elements" <<  endl;
                    int number;
                    input(&number);
                    for (int i = 0; i < number; i++) {
                        cout << "Enter value" << endl;
                        int value;
                        input(&value);
                        newQueue -> append(value);
                    }
                    queue -> concat(*newQueue);
                    break;
                }
                case 9: {
                    int startIndex, endIndex;
                    input(&startIndex);
                    input(&endIndex);
                    cout << queue -> getSubsequence(startIndex, endIndex) << endl;
                    break;
                }
                default:
                    break;
            }
        }
    } else {
        cout << "1. Queue" << endl << "2. QueueArray" << endl;
        int type = -1;
        do {
            input(&type);
        } while (type != 1 && type != 2);
        Queue<double> *queue;
        QueueArray<double> *seq2;
        if (type == 1) {
            queue = new Queue<double>();
        } else {
            seq2 = new QueueArray<double>();
        }
        cout << "1. Append" << endl << "2. Prepend" << endl << "3. Get length" << endl << "4. Print" << endl << "0. Exit" << endl;
        while (true) {
            type = -1;
            int index;
            while (type < 0 || type > 6) {
                cout << "Choose option" << endl;
                input(&type);
            }
            int item;
            switch (type) {
                case 0:
                    exit(0);
                    break;
                case 1:
                    cout << "Enter appending item" << endl;
                    input(&item);
                    queue -> append(item);
                    break;
                case 2:
                    cout << "Enter prepend item" << endl;
                    input(&item);
                    queue -> prepend(item);
                    break;
                case 3:
                    cout << "The length is: " << queue -> getSize() << endl;
                    break;
                case 4:
                    cout << queue << endl;
                    break;
            }
        }
    }
}

int main() {
    menu();
    return 0;
}
