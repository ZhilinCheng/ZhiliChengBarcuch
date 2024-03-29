#pragma once
#ifndef Array_HPP
#define Array_HPP
template <typename T>
class Array
{
private:
	T* m_data; // Dynamic C array of Point objects
	int m_size; // Size of the array
	static int m_static_size; // Static member indicating the default size

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
	static int DefaultSize();

	// Modifiers
	void SetElement(int index, const T& newT);
	static void DefaultSize(int size);

};
#endif
