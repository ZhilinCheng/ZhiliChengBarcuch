
#include "Point.hpp"
#include <sstream>
#include <iostream>

// Constructors and destructor
Point::Point() : Shape()
{ 
	// Default constructor
	m_x = 0.0;
	m_y = 0.0;
}

Point::Point(const Point& source) : Shape(source)
{ 
	// Copy constructor
	m_x = source.m_x;
	m_y = source.m_y;
}

Point::Point(double xValue, double yValue) : Shape()
{ 
	// Constructor accepting x- and y-coordinates
	m_x = xValue;
	m_y = yValue;
}

Point::~Point()
{ // Destructor
	//cout << "Point destructor called." << endl;
}

Point& Point::operator = (const Point& source)
{ 
	// Assignment operator

	// Exit if same object
	if (this == &source)
	{
		return *this;
	}

	// Call base class assignment
	Shape::operator = (source);

	// Copy state
	m_x = source.m_x;
	m_y = source.m_y;

	return *this;
}

ostream& operator << (ostream& os, const Point& p)
{ 
	// Send to ostream

	os << "Point(" << p.m_x << "," << p.m_y << ")";

	return os;
}

string Point::ToString() const
{
	stringstream stream;
	std::string s = Shape::ToString();

	stream << "Point(" << m_x << "," << m_y << "), " << s;

	return stream.str();
}

void Point::Draw() const
{
	cout << "Draw a point." << endl;
}