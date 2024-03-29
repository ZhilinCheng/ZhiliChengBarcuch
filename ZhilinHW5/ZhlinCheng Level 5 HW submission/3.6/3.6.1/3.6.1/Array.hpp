#ifndef Array_HPP
#define Array_HPP

#include "Point.hpp"
using namespace std;

class Array
{
private:
	Point* m_data; // Dynamic C array of Point objects
	int m_size; // Size of the array

public:
	// Con structors
	Array();
	Array(int size);
	Array(const Array& pp);
	virtual ~Array();

	// Member operator overloading
	Array& operator = (const Array& source);
	Point& operator [] (int index);
	const Point& operator [] (int index) const;

	// Accessing functions
	int Size() const;
	Point& GetElement(int index) const;

	// Modifiers
	void SetElement(int index, const Point& newPoint);
};

#endif