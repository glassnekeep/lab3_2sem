#include <iostream>
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include "Queue.h"

using namespace std;

template<class T>
void input(T* value) {
    while (true) {
        cin >> *value;
        break;
    }
}

void menu() {
    int data_type = 0;
    cout << "1. int" << endl << "2. double" << endl;
    do {
        input(&data_type);
    } while (data_type != 2 && data_type != 1);
    if (data_type == 1) {
        cout << "1. ListSequence" << endl << "2. ArraySequence" << endl;
        int type = -1;
        do {
            input(&type);
        } while (type != 1 && type != 2);
        Queue<int> *seq;
        if (type == 1) {
            seq = new LinkedListSequence<int>();
        } else {
            seq = new ArraySequence<int>;
        }
        cout << "1. Append" << endl << "2. Prepend" << endl << "3. Insert at" << endl << "4. Get length" << endl << "5. Print" << endl << "6. Subsequence" << endl << "0. Exit";
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
                    seq -> append(item);
                    break;
                case 2:
                    cout << "Enter prepend item" << endl;
                    input(&item);
                    seq -> prepend(item);
                    break;
                case 3:
                    cout << "Enter insert index" << endl;
                    input(&index);
                    try {
                        cout << "Enter insert item" << endl;
                        input(&item);
                        seq -> insertAt(item, index);

                    } catch (Exception& exception) {
                        cout << "Process finished with error code = " << exception.number << endl;
                        exit(0);
                    }
                    break;
                case 4:
                    cout << "The length is: " << seq -> getLength() << endl;
                    break;
                case 5:
                    cout << seq << endl;
                    break;
                case 6:
                    int fromIndex;
                    int toIndex;
                    cout << "Enter start index" << endl;
                    input(&fromIndex);
                    cout << "Enter end index" << endl;
                    input(&toIndex);
                    Sequence<int> *seq2 = seq -> getSubsequence(fromIndex, toIndex);
                    cout << "Subsequence : " << seq2 << endl;
            }
        }
    } else {
        cout << "1. ListSequence" << endl << "2. ArraySequence" << endl;
        int type = -1;
        do {
            input(&type);
        } while (type != 1 && type != 2);
        Sequence<double> *seq;
        if (type == 1) {
            seq = new LinkedListSequence<double>();
        } else {
            seq = new ArraySequence<double>;
        }
        cout << "1. Append" << endl << "2. Prepend" << endl << "3. Insert at" << endl << "4. Get length" << endl << "5. Print" << endl << "6. Subsequence" << endl << "0. Exit";
        while (true) {
            type = -1;
            int index;
            while (type < 0 || type > 6) {
                cout << "Choose option" << endl;
                input(&type);
            }
            double item;
            switch (type) {
                case 0:
                    exit(0);
                    break;
                case 1:
                    cout << "Enter appending item" << endl;
                    input(&item);
                    seq -> append(item);
                    break;
                case 2:
                    cout << "Enter prepend item" << endl;
                    input(&item);
                    seq -> prepend(item);
                    break;
                case 3:
                    cout << "Enter insert index" << endl;
                    input(&index);
                    try {
                        cout << "Enter insert item" << endl;
                        input(&item);
                        seq -> insertAt(item, index);
                    } catch (Exception& exception) {
                        cout << "Process finished with error code = " << exception.number << endl;
                        exit(0);
                    }
                    break;
                case 4:
                    cout << "The length is: " << seq -> getLength() << endl;
                    break;
                case 5:
                    cout << seq << endl;
                    break;
                case 6:
                    int fromIndex;
                    int toIndex;
                    cout << "Enter start index" << endl;
                    input(&fromIndex);
                    cout << "Enter end index" << endl;
                    input(&toIndex);
                    Sequence<double> *seq2 = seq -> getSubsequence(fromIndex, toIndex);
                    cout << "Subsequence : " << seq2 << endl;
            }
        }
    }
}

int main() {
    menu();
    return 0;
}
