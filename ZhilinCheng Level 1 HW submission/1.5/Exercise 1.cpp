#include <stdio.h>
double minus(double x, double y)
{
	double diff = x - y;
	return diff;
}
int main()
{
	double a = 1, b = 2;
	double c = minus(a, b);
	printf("The difference between %f and %f is %f", a, b, c);
	getchar();
	return 0;
}