#include <iostream>
#include <stdexcept>
#include "Vector.h"

using namespace std;

template<typename T> Vector<T>::Vector(){

    vector = new T[2];
    _capacity = 2;
    _size = 0;
}

template<typename T> Vector<T>::Vector(const Vector& copy_vector){

    _size = _capacity = copy_vector._size;
    vector = new T[_capacity];

    unsigned i = 0;
    for(;i < copy_vector._size; i++)
        *(vector + i) = copy_vector.vector[i];
}

template<typename T> Vector<T>::Vector(Vector&& move_vector){

    vector = move_vector.vector;
    _size = move_vector._size;
    _capacity = move_vector._capacity;
    move_vector.vector = nullptr;
    move_vector._size = 0;
    move_vector._capacity = 0;
}

template<typename T> Vector<T>::~Vector(){
    
    if(vector != nullptr){
            
        delete[] vector; 
        vector = nullptr;
    }
}

template<typename T> T& Vector<T>::operator[](size_t position){

    if(position >= _size || position < 0) 
        throw out_of_range("Index out of range\n");

    return *(vector + position);
}


template<typename T> const T& Vector<T>::operator[](size_t position) const{

    if(position >= _size || position < 0) 
        throw out_of_range("Index out of range\n");

    return *(vector + position);
}

template<typename T> Vector<T>& Vector<T>::operator=(const Vector& right){

    if(this != &right){

        if(right._size > _capacity) {

            delete[] vector;
            vector = new T[right._size];
            _capacity = right._size;
        }

        _size = right._size;

        unsigned i = 0;
        for(;i < right._size; i++)
            *(vector + i) = right.vector[i];

    }

    return *this;
}

template<typename T> Vector<T>& Vector<T>::operator=(Vector&& right){

    if(this != &right){

        delete[] vector;
        vector = right.vector;
        _size = right._size;
        _capacity = right._capacity;
        right.vector = nullptr;
        right._size = 0;
        right._capacity = 0;
    }

    return *this;
}

template<typename T> void Vector<T>::expand(size_t new_capacity){

    if(new_capacity < 0) 
        throw invalid_argument("Invalid argument for capacity\n");

    T* temp = new T[new_capacity];

    unsigned i = 0;
    for(; i < _size; i++)
        *(temp + i) = *(vector + i);

    delete[] vector;
    vector = temp;
    _capacity = new_capacity;
}

template<typename T> size_t Vector<T>::size() const{

    return _size;
}

template<typename T> void Vector<T>::push_back(const T& value){

    if(_size >= _capacity)
       expand(_size * 2);
    
    *(vector + _size) = value;
    _size ++;
}

template<typename T> void Vector<T>::pop_back(){

    if(!empty())
        _size--;
}

template<typename T> void Vector<T>::resize(size_t new_size, T value){

    if(new_size < 0) 
        throw out_of_range("Index out of range\n");

    if(_size < new_size){

        if(new_size > _capacity)
            expand(new_size);

        for(;_size < new_size; _size++)
            *(vector + _size) = value;
    }

    while(_size > new_size)
        pop_back();
}

template<typename T> bool Vector<T>::empty() const{

    return _size == 0;
}

template<typename T> T& Vector<T>::back(){

    if(_size == 0) 
        throw out_of_range("Index out of range\n");

    return *(vector + _size - 1);
}

template<typename T> const T& Vector<T>::back() const{
    
    if(_size == 0) 
        throw out_of_range("Index out of range\n");
    
    return *(vector + _size - 1);
}

template<typename T> void Vector<T>::clear(){

    _size = 0;
}

template<typename T> typename Vector<T>::Iterator Vector<T>::begin(){

    return Iterator(vector);
}

template<typename T> typename Vector<T>::Iterator Vector<T>::end(){

    return Iterator(vector + _size);
}

template<typename T> void Vector<T>::display(){

    if(empty()){

        cout << "Empty vector"<< endl;
        return;
    }

    unsigned i = 0;
    for(; i < _size; i++)
        cout << *(vector + i) << " ";
    
    cout << endl;
}

int main() {

    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(13);

    v.display();

    Vector<int> v1 = v;
    v1.display();
    Vector<int> v2 (move(v));
    v2.back() = 18;
    v2[1] = 22;
    v2.display();
    v.display();
    v1.resize(2, 4);
    v1.display();

    try{
        v1[1] = 4;
        v.back();
    }
    catch(exception& e){

        cout << "Caught: " << e.what();
        cout << "Type: " << typeid(e).name() << endl;
    }
}
