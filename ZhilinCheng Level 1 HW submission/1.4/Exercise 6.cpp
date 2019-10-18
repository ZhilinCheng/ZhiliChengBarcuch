#include <stdio.h>
#include <Windows.h>
int main()
{
	int c = 0;
	int zero = 0, one = 0, two = 0, three = 0, four = 0, other = 0;
	while (c != 4)
	{
		c = getchar();
		switch (c)
		{
		case 48:
			zero++;
			break;
		case 49:
			one++;
			break;
		case 50:
			two++;
			break;
		case 51:
			three++;
			break;
		case 52:
			four++;
			break;
		default:
			other++;
			break;
		}
	}
	printf("the  number of 1,2,3,4 is\n%d%d%d%d%d", zero, one, two, three, four, other);
	system("pause");
	return 0;
}
