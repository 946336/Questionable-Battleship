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

		T& operator[] (int index);
		dynArray<T>& operator= (const dynArray &source);
		dynArray<T>& operator+= (const T &source);

		int getSize();
		bool add(T newElement);
		T& at(int where);
		bool isEmpty();

		friend class MainMenu;
		friend class SettingsMenu;
		friend class PauseMenu;

	private:
		T *arr;
		int size, capacity;
		
		bool expand();
};

#include "dynamicArray.cpp"

#endif