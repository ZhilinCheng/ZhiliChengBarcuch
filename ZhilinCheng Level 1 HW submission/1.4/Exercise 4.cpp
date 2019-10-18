#include <stdio.h>
int main()
{
	double Fahrenheit, Celsius;
	Fahrenheit = 0;
	while (Fahrenheit <= 300)
	{
		Celsius = 5. / 9 * (Fahrenheit - 32);
		Fahrenheit = Fahrenheit + 20;
		printf("The Fahrenheit and Celsius degree are\n%f%10.1f\n", Fahrenheit, Celsius);

	}

	getchar();
}