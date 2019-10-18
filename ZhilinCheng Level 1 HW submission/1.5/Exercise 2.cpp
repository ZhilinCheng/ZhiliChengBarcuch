#include <stdio.h>
double factorial(int x)
{
	if (x >= 1)
	{
		return (x * (factorial(x - 1)));
	}
	else	
	{
		return 1;

	}
}
int main()
{
	int c = factorial(6);
	printf("the factorial of the number is%d", c);
	getchar();
	return 0;

}