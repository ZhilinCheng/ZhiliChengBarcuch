#include <stdio.h>
int printnumber(int number)
{
	
		if (number < 0)

		{
			number *= -1;
			putchar(number + '0');
		}
		if (number <= 10)
		{
			putchar(number % 10 + '0');
			return 0;
				}
		else
		{
			putchar(number%10 + '0');
			number = number / 10;
			printnumber(number);
		}


}
int main()
{
	int i = 155322;
	printnumber(i);
	getchar();
}