#ifndef VECTOR_H
#define VECTOR_H

#include<iostream>
#include<string>

template<class T>
class Vector{
private:
    int size_v;// the number of elements stored in the vector

    T* elem;// a pointer to the elements

    int space;// The maximum storage of the vector
public:
    Vector(): size_v{0}, elem{nullptr}, space{0}{}// default constructor

    explicit Vector(int s): size_v{0}, elem{ new T[s]}, space{s}
    {// alternate constructor

    }

    Vector(const Vector& src): size_v{src.size()}, elem{ new T[src.capacity()]}, space{src.capacity()}
    {	// copy constructor
        // Copy the elements over
        for (int i = 0; i < size_v; i++)
        {
            elem[i] = src.elem[i];
        }

    }

    Vector(Vector&& src){// move constructor
        elem = src.elem;
        size_v = src.size_v;

        src.elem = nullptr;
        src.size_v = 0;
    }

    Vector& operator=(const Vector& src){// copy assignment
        delete[] elem;// free the old space

        size_v = src.size();// copy value of size
        space = src.capacity();// copy value of space
        elem = new T[space];// create new space

        for (int i = 0; i < size_v; i++)
        {
            elem[i] = src.elem[i];
        }

        return *this;
    }

    Vector& operator=(Vector&& src) // move assignment
    {
        if(this != &src)
        {
            delete[] elem;

            elem = src.elem;
            size_v = src.size();
            space = src.capacity();

            src.elem = nullptr;
            src.size_v = 0;
            src.space = 0;
        }
        return *this;
    }

    ~Vector()// destructor
    {
        delete[] elem;
    }


    T& operator[](int n)// access: return reference
    {
        if (n < size_v)
        {
            return elem[n];
        }
        std::cout << "out of bounds";
        //throw outOfBounds();
    }

    T* getArrayFromVector()
    {
        return elem;
    }

    const T& operator[](int n) const // access: return reference
    {
        if (n < size_v)
        {
            return elem[n];
        }
        std::cout << "out of bounds";
        //throw outOfBounds();
    }

    int size() const // the current size
    {
        return size_v;
    }

    int capacity() const
    {// current available space
        return space;
    }

    void resize(int newsize)
    {// grow the vector and give default values to the new elements
        reserve(newsize);
        for (int i = size_v; i < newsize; i++)
        {
            elem[i] = T();
        }
        size_v = newsize;
    }

    void push_back(T val){ // add element
        if (size_v == 0)// vector is empty
        {
            reserve(10);
        }
        else if (size_v == space)// vector is full
        {
            reserve(2 * space);
        }
        elem[size_v] = val;
        size_v++;
    }

    void reserve(int newalloc){//get more space
        if (newalloc > space)
        {
            space = newalloc;
            T* newElem = new T[space];
            for (int i = 0; i < size_v; i++)
            {
                newElem[i] = elem[i];
            }
            delete[] elem;

            elem = newElem;
        }
        else
        {
            std::cout << "Invalid size";
            //throw invalidSize();
        }

    }

    void print(){
        for (int i = 0; i < size_v; i++){
            std::cout << elem[i] << " ";
        }
        std::cout << std::endl;
    }

    using iterator = T*;

    using const_iterator = const T*;

    iterator begin()
    {// points to first element
        // returns null pointer if no elements
        // else return the address of first element
        if (size_v == 0)
        {
            return nullptr;
        }
        return &elem[0];
    }

    const_iterator begin() const
    {
        // returns null pointer if no elements
        // else return the address of first element
        if (size_v == 0)
        {
            return nullptr;
        }
        return &elem[0];

    }

    iterator end(){
        // returns null pointer if no elements
        if (size_v == 0)
        {
            return nullptr;
        }
        return &elem[size_v];
    }

    const_iterator end() const{
        // returns null pointer if no elements
        if (size_v == 0)
        {
            return nullptr;
        }
        return &elem[size_v];// Size_v is always 1 more than element index


    }

    iterator insert(iterator p, const T& v){// insert a new element v before p
        if (p < begin())
        {
            std::cout << "out of bounds";
            //throw iteratorOutOfBounds();
        }
        if (size_v + 1 > space)// make sure theres space
        {
            reserve(2 * space);// give it more slots if there isnt enough space
        }
        for (iterator pos = end(); pos != p; --pos)// shift all elements to the right of 1
        {
            *pos = *(pos - 1);
        }
        *p = v;// write in v at p
        size_v++;

        return p;

    }

    iterator erase(iterator p){// remove element pointed to by p
        if (p > end())//
        {
            std::cout << "out of bounds";
            //throw iteratorOutOfBounds();
        }
        else if (p == end())
        {
            return p;
        }
        for (iterator pos = p + 1; pos != end(); ++pos)// start at p + 1 because iterators are equality comparative
        {
            *(pos - 1) = *pos;// shift elements to the left of p left
        }
        *(end() - 1) = T();// Set element at the end to default value
        size_v--;// decrease size
        return p;
    }
};



#endif // VECTOR_H
