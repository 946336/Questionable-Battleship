#ifndef DYNAMIC_ARRAY_BODY_CPP
#define DYNAMIC_ARRAY_BODY_CPP

#ifndef DYNAMICARAY_H
	#include "dynamicArray.h"
#endif
#include <cstdlib>
#include <iostream>

template <typename T>
dynArray<T>::dynArray(){
	arr = NULL;
	size = capacity = 0;
}

template <typename T>
dynArray<T>::dynArray(T *entries, int len){
	arr = new T[len];
	size = capacity = len;
	for(int i = 0; i < len; ++i){
		arr[i] = entries[i];
	}
}

template <typename T>
dynArray<T>::dynArray(int cap){
	arr = new T[size];
	capacity = cap;
}

template <typename T>
dynArray<T>::~dynArray(){
	delete [] arr;
}

/*
subscript overload
Also this isn't safe :\
*/
template <typename T>
T& dynArray<T>::operator[] (int &index){
	return arr[index];
}

// Copy constructor overload
template <typename T>
dynArray<T>::dynArray(const dynArray &source){
	size = source.size;
	capacity = source.capacity;
	// Copy array contents
	arr = new T[source.capacity];
	for(int i = 0; i < source.size; ++i){
		arr[i] = source.arr[i];
	}
}

// Assignment overload
template <typename T>
dynArray<T>& dynArray<T>::operator= (const dynArray &source){
	if(this == &source){
		return *this;
	}
	delete arr;
	arr = new T[source.capacity];
	size = source.size;
	capacity = source.capacity;
	for(int i = 0; i < size; ++i){
		arr[i] = source.arr[i];
	}
	return *this;
}

template <typename T>
bool dynArray<T>::expand(){
	int newCap = 2 + 2 * capacity;
	T *newArr = new T[newCap];
	for(int i = 0; i < size; ++i){
		newArr[i] = arr[i];
	}
	delete [] arr;
	arr = newArr;
	capacity = newCap;
	return true;
}

template <typename T>
bool dynArray<T>::add(T newElement){
	if(size >= capacity){
		if(!expand()) return false;
	}
	arr[size] = newElement;
	++size;
	return true;
}

template <typename T>
int dynArray<T>::getSize(){
	return size;
}

#endif