#include "Array.cpp"
#include "Point.hpp"
#include <iostream>
using namespace std;
int main()
{
	int size = 3;
 	// Create two arrays of points.
	Array<Point> points(size);
	Array<Point> points2(size);
	points[0] = Point(1, 2);
	points[1] = Point(3, 4);
	points[2] = Point(5, 6);
	// Test assignment operator and [] operator for reading.
	points2 = points;
	for (int i = 0; i < size; i++)
	{
		cout << points2[i] << endl;
	}

	// Test GetElement().
	cout << "Elements: " << points.GetElement(0) << ", " << points.GetElement(1) << ", " << points.GetElement(2) << endl;

	// Test SetElement().
	points2.SetElement(0, Point(1, 2));
	points2.SetElement(1, Point(3, 4));
	points2.SetElement(2, Point(5, 6));
	cout << "Elements: " << points2[0] << points2[1]<< points2[2] << endl;
	// Using copy constructor.
	Array<Point> points3(points2);
	cout << "Elements: " << points3[0] << ", " << points3[1] << ", " << points3[2] << endl;

	// Test [] operator for const Array object.
	const Array<Point> points4(points2);
	cout << "Elements: " << points4[0] << ", " << points4[1] << ", " << points4[2] << endl;
}
