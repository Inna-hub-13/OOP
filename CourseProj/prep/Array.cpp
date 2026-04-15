#include <stdlib.h>
#include <iostream>
#include "Array.h"
using namespace std;

template <typename T> Array<T>::Array(){

    arr = nullptr;
    size = 0;
}

template <typename T> Array<T>::Array(int sizeArr){

    if(sizeArr<0)
        sizeArr = 5;
    
    arr = new T[sizeArr];
    size = sizeArr;
}

template <typename T> void Array<T>::fill(T value) {

    int i;
    for(i = 0; i < size; i++)
        *(arr + i) = value;
}

template <typename T> T& Array<T>::at(int index){

    return *(arr + index);
}

template <typename T> void Array<T>::print(){

    int i;
    cout<<"Size: "<<size<<endl;
    for(i = 0; i < size; i++)
        cout<<*(arr + i)<<" ";

    cout<<"\n";
}

int main() {

    Array<int> arrInt(10);
    arrInt.fill(11);
    arrInt.at(3) = 8;

    arrInt.print();

    Array<double> arrDouble(3);
    arrDouble.fill(5.5);

    arrDouble.print();

    return 0;
}