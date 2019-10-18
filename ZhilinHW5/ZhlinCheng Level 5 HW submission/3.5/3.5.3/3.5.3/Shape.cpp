#include "Shape.hpp"
#include <stdlib.h>
#include <sstream>
#include <iostream>


// Constructors and destructor
Shape::Shape() : m_id(rand())
// Default constructor
{
}

Shape::Shape(const Shape& source) : m_id(source.m_id)
// Copy constructor
{
	cout << "Shape destructor called." << endl;

}

Shape::~Shape()
// Destructor
{
}

// Operator overloading
Shape& Shape::operator = (const Shape& source)
{
	// Assignment operator
	if (this == &source)
	{
		return *this;
	}

	m_id = source.m_id;

	return *this;
}

string Shape::ToString() const
{
	stringstream stream;

	stream << "ID: " << m_id;

	return stream.str();
}

// Accessing functions
int Shape::ID() const
{
	return m_id;
}