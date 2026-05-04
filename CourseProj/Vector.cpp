#include <iostream>
#include "Vector.h"

using namespace std;

template<typename T> Vector<T>::Vector(){

    vector = new T[2];
    _capacity = 2;
    _size = 0;
}

template<typename T> Vector<T>::Vector(Vector& copy_vector){

    _size = _capacity = copy_vector.size();
    vector = new T[_capacity];

    unsigned i = 0;
    for(auto el : copy_vector){
        
        *(vector + i) = el;
        i++;
    }
}

template<typename T> T& Vector<T>::operator[](size_t position){

    return *(vector + position);
}


template<typename T> const T& Vector<T>::operator[](size_t position) const{

    return *(vector + position)
}

template<typename T> Vector<T>& Vector<T>::operator=(const Vector& right){

    if(right.size() > _capacity){

        delete[] vector;
        vector = new T[right.size()];
        _capacity = right.size();
    }

    _size = right.size();

    unsigned i = 0;
    for(auto el : right){
        
        *(vector + i) = el;
        i++;
    }
}

template<typename T> void Vector<T>::expand(size_t new_capacity){

    Vector temp(*this);
    delete[] vector;
    vector = new T[new_capacity];
    _capacity = new_capacity;

    unsigned i  = 0;
    for(auto el : temp){

        *(vector + i) = el;
        i++;
    }
}

template<typename T> unsigned  Vector<T>::size() const{

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

    return *(vector + _size);
}

template<typename T> const T& Vector<T>::back() const{

    return *(vector + _size);
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

int main() {

    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(13);

    Vector<int>::Iterator it = v.begin();
    for(; it != v.end(); it++)
        cout<< *it <<endl;

    v.pop_back();

    cout << "After ="<<endl;

    Vector<int> v1 = v;

    for(it = v1.begin(); it != v1.end(); it++)
        cout<< *it <<endl;
}
