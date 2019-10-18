#include <stdio.h>
int main()
{
	for (int i = 10; i > 0; i--)
	{
		printf("%d\n", i--);
	}
	for (int i = 10; i > 0; i--)
	{
         getchar();
		 printf("%d\n",--i);
	}
}