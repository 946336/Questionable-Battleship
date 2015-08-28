#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template <typename T> struct dynArray;

template <typename T>
struct dynArray{
	public:
		dynArray();
		dynArray(T *entries, int len);
		dynArray(int cap);
		dynArray(const dynArray &source);
		~dynArray();

		T& operator[] (int &index);
		dynArray& operator= (const dynArray &source);

		int getSize();
		bool add(T newElement);

		// a
	private:
		T *arr;
		int size, capacity;
		
		bool expand();
};

#include "dynamicArray.cpp"

#endif
