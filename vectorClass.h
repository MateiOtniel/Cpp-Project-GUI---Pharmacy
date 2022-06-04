#pragma once
#include "domain.h"
#include <iostream>
using namespace std;
template <typename Medicament>
class vectorClass{
private:
    Medicament* arr;
    int capacity;
    int current;
public:
    // Default constructor to initialise
    // an initial capacity of 1000 Medicament and
    // allocating storage using dynamic allocation
    vectorClass(){
        arr = new Medicament[1000];
        capacity = 1000;
        current = 0;
    }

    // Function to add an element at the last
    void push_back(const Medicament& data){
        arr[current] = data;
        current++;
    }

    // function to add element at any index
    void push(const Medicament& data, int index){
        arr[index] = data;
    }

    // function to extract element at any index
    Medicament& get(int index){
        return arr[index];
    }

    // function to delete last element
    void pop(int index){
        for(int i = index; i < current - 1; i++)
            arr[i] = arr[i + 1];
        current--;
    }

    // function to get size of the vector
    int size(){
        return current;
    }

    // function to get capacity of the vector
    int getcapacity(){
        return capacity;
    }

    ~vectorClass(){
        delete[] this->arr;
    }
};
