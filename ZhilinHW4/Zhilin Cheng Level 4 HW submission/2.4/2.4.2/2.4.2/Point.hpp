#pragma once
#ifndef Point_HPP
#define Point_HPP

#include <iostream>
using namespace std;

class Point
{ 
private:
	double m_x; // x-coordinate
	double m_y; // y-coordinate

public:
	// Constructors
	Point();
	Point(const Point& point);
	Point(double xValue, double yValue);
	~Point();

	// Accessing functions
	double X() const;
	double Y() const;

	// settter
	void X(double newX);
	void Y(double newY);

	string Tostring() const;

	// Functionality
	double Distance() const;
	double Distance(const Point& p) const;

	// Member operator overloading
	Point operator - () const; // Negate the coordinates
	Point operator * (double factor) const; // Scale the coordinates
	Point operator + (const Point& p) const; // Add coordinates
	bool operator == (const Point& p) const; // Equally compare operator
	Point& operator = (const Point& source); // Assignment operator
	Point& operator *= (double factor); // Scale the coordinates & assign
};

ostream& operator << (ostream& os, const Point& p); // Send to ostream

#endif