//
// Created by - on 27.04.2022.
//

#ifndef LAB2_2SEM_DYNAMICARRAY_H
#define LAB2_2SEM_DYNAMICARRAY_H

#include <cassert>
#include "Exception.h"

using namespace std;

template <class T> class DynamicArray {
private:
    int size;
    int capacity;
    T* value;
public:
    DynamicArray(T* items,int length);
    DynamicArray(int count);
    DynamicArray(const DynamicArray<T>& array);
    int getSize() const ;
    int getCapacity() const;
    T get(int index);
    void set(int index, T data);
    void resize(int newSize);
    void push(T data);
    T& operator[](int index);
};

//Изменено
template<typename T>
ostream & operator << (ostream& out, DynamicArray<T> array) {
    for (int i = 0; i < array.GetSize(); ++i) {
        out << array.get(i) << " "; 
    }
    return out;
}

template <class T>
DynamicArray<T>::DynamicArray(T* items, int length) {
    {
        size = length;
        capacity = length;
        value = new T[size];
        for (int i = 0; i < size; i++) {
            value[i] = items[i];
        }
    }
}

template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& array) {
    size = array.size;
    capacity = array.capacity;
    value = NULL;
    if (size != 0)
        value = new T[size];
    else
        value = 0;
    for (int i = 0; i < size; ++i)
        value[i] = array.value[i];
}

template <class T>
DynamicArray<T>::DynamicArray(int count) {
    size = count;
    capacity = count;
    if (count != 0)
        value = new T[count];
    else
        value = 0;
}

template <class T>
int DynamicArray<T>::getSize() const {
    return size;
}

template <class T>
int DynamicArray<T>::getCapacity() const {
    return capacity;
}

template <class T>
T DynamicArray<T>::get(int index) {
    if (index > size - 1 || index < 0) {
        throw Exception(1);
    }
    return value[index];
}

template <class T>
void DynamicArray<T>::set(int index, T data) {
    if (index > size - 1 || index < 0) {
        throw Exception(1);
    }
    value[index] = data;
}

template <class T>
T& DynamicArray<T>::operator[](int index) {
    if (index > size - 1 || index < 0) {
        throw Exception(1);
    }
    return value[index];
}

template <class T>
void DynamicArray<T>::resize(int newSize) {
    if (newSize < 0) { throw Exception(3); }
    if (newSize > capacity) {
        int newCapacity = max (newSize, size * 2);
        T* newData = new T[newCapacity];
        for (int i = 0; i < size; i++) { newData[i] = value[i]; }
        value = newData;
        capacity = newCapacity;
    }
    else {
        if (newSize < size) {
            for (int i = newSize; i < size; i++) { value[i] = 0; }
        }
    }
    size = newSize;
}

template <class T>
void DynamicArray<T>::push(T data) {
    try {
        resize(size + 1);
        value[size - 1] = data;
    }
    catch (Exception& exception) {
        exception.show();
    }
}

#endif //LAB2_2SEM_DYNAMICARRAY_H
