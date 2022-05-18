//
// Created by - on 27.04.2022.
//

#ifndef LAB22SEMARRAYSEQUENCEH
#define LAB22SEMARRAYSEQUENCEH


#include "Sequence.h"
#include "DynamicArray.h"

using namespace std;

template <class T>class ArraySequence: public Sequence <T> {
private:
    DynamicArray<T> * array;
    int size;

public:
    ArraySequence();
    ArraySequence(int count);
    ArraySequence(T* items,int count);
    ArraySequence(const DynamicArray <T> &newArray );
public:
    int getLength() override;
    int getCapacity();
    T getFirst() override;
    T getLast() override;
    T get(int index) override;
    Sequence<T>* getSubsequence(int fromIndex,int toIndex ) override;
    void insertAt(T item,int index) override;
    void append(T item) override;
    T& operator[](int index)override;
    void prepend(T item) override;
    Sequence <T> * concat(Sequence <T> * list)override;

};
template<typename T>
ostream & operator << (ostream& out, ArraySequence<T>* a) {
    try {
        for (int i = 0; i < a -> getLength(); ++i) {
            out << a->get(i) << " ";
        }
        return out;
    }
    catch (Exception& exception) {
        throw exception;
    }
}

template<typename T>
ostream & operator << (ostream & out, ArraySequence<T> a) {
    try {
        for (int i = 0; i < a.getLength(); ++i) {
            out << a.get(i) << " ";
        }
        return out;
    }
    catch (Exception& exception) {
        throw exception;
    }
}

template<class T>
ArraySequence<T>::ArraySequence() {
    array = new DynamicArray<T> (0);
    size = 0;
}

template<class T>
ArraySequence<T>::ArraySequence(int count) {
    array = new DynamicArray<T> (count);
    size = count;
}

template<class T>
ArraySequence<T>::ArraySequence(T* items,int count) {
    array = new DynamicArray<T>(items, count);
    size = count;
}

template<class T>
ArraySequence<T>::ArraySequence(const DynamicArray <T>& newArray ) {
    array = new DynamicArray <T>(newArray);
    size = newArray.getSize();
}

template<class T>
int ArraySequence<T>::getLength() {
    return size;
}

template<class T>
int ArraySequence<T>::getCapacity() {
    return array -> getCapacity();
}

template<class T>
T ArraySequence<T>::getFirst() {
    try {
        return array -> get(0);
    } catch (Exception& exception) {
        throw exception;
    }
}

template <class T>
T ArraySequence<T>::getLast() {
    try {
        return array->get(size-1);
    } catch (Exception& exception) {
        throw exception;
    }
}

template <class T>
T ArraySequence<T>::get(int index) {
    try {
        T a = array -> get(index);
        return a;
    } catch (Exception& exception) {
        throw exception;
    }
}

template <class T>
Sequence <T>* ArraySequence<T>::getSubsequence(int fromIndex,int toIndex ) {
    try {
        DynamicArray<T> buffer(toIndex - fromIndex + 1);
        for (int i = fromIndex; i <= toIndex; i++) {
            buffer[i - fromIndex] = (*array)[i];
        }
        Sequence<T>* subSequence = new ArraySequence(buffer);
        return subSequence;
    } catch (Exception& exception) {
        throw exception;
    }
}

template <class T>
void ArraySequence<T>::insertAt(T item,int index) {
    try {
        array -> resize(array -> getSize() + 1);
        size++;
        T ptr = (*array)[index];
        T tmp;
        for (int i = index + 1; i < size; i++) {
            tmp = (*array)[i];
            (*array)[i] = ptr;
            ptr = tmp;
        }
        (*array)[index] = item;
    } catch (Exception& exception) {
        size--;
        throw exception;
    }
}

template <class T>
void ArraySequence<T>::append(T item) {
    insertAt(item, size);
}

template <class T>
void ArraySequence<T>::prepend(T item) {
    insertAt(item, 0);
}

template <class T>
T& ArraySequence<T>::operator[](int index) {
    try {
        return (*array)[index];
    } catch(Exception& exception) {
        throw exception;
    }
}

template <class T>
Sequence <T>* ArraySequence<T>::concat(Sequence<T> * list) {
    if (list == NULL) {
        throw Exception(2);
    }
    try {
        auto *result = new ArraySequence<T>;
        result -> array = array;
        result -> size = size;
        for (int i = 0; i < list -> getLength(); i++) {
            result -> append((*list)[i]);
        }
        return result;
    } catch (Exception& exception) {
        throw exception;
    }
}

#endif //LAB22SEMARRAYSEQUENCEH