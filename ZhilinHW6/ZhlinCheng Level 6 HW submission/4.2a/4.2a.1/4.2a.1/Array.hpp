#pragma once
#ifndef Array_HPP
#define Array_HPP
template <typename T>
class Array
{
private:
	T* m_data; // Dynamic C array of Point objects
	int m_size; // Size of the array

public:
	// Constructors
	Array();
	Array(int size);
	Array(const Array<T>& pt);
	// Destructor
	~Array();
	// Member operator overloding
	Array<T>& operator = (const Array<T>& source);
	T& operator [] (int index);
	const T& operator [] (int index) const;
	// Accessing functions
	T& GetElement(int index) const;
	// Modifiers
	void SetElement(int index, const T& newT);
};
#endif
