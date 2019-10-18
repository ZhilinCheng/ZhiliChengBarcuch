#include <stdio.h>
int main()
{
	double Fahrenheit, Celsius;
	for (Celsius = 0; Celsius <= 19; Celsius++)
	{
 		Fahrenheit = 9. / 5*Celsius + 32;
		printf("The Celsius and Fahrenheit degree are\n%f%10.1f\n", Celsius, Fahrenheit);

 	}
	getchar();

}