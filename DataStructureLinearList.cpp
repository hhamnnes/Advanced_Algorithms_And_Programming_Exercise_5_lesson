#include<iostream>

//Of what I understand, a linear list consist of a sequence of elements, where
//each of the elements is connected to the next element in the list. Each element 
//therefore have a value and a pointer, apart from the last element which only have a value and 
//the header which only have a pointer.

//Furthermore, a linear list data structure often have the following operations:
//1. Length of the list
//2. Read
//3. Search
//4. Insert
//5. Delete

//I will use template to write the abstract class for the linear data structure.
template<typename T> //This is how we can make this template work
//for any sort of data type.

//This will be the name of the abstract class.
class LinearList { 
public:
    //length shall return the length of the list as an integer, which 
    //reflects how may elements there are in the list.
    virtual int length() const = 0;
    //The read function shall return all values of the list.
    virtual T read() const = 0; 
    //The search function shall return a integer, which represents the position
    //of the value in the list.
    virtual int search(const T& value) const = 0;
    //The insert function shall insert a given value at a given index in the 
    //list.
    virtual void insert(int index, const T& value) = 0;

    //The remove function shall remove a value in the list at a given index.
    virtual void remove(int index) = 0;

    //The destructor shall delete the list. We use it to avoid memory leaks.
    virtual ~LinearList() {}
};


