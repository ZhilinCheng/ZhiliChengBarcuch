#include <stdio.h>
#include <Windows.h>
int main()
{
	int c = 0;
	int  three = 0, other = 0;
	while (c != 4)
	{
		c = getchar();
		switch (c)
		{
		case 51:
			three++;
			break;
		default:
			other++;
			break;
		}
	}
	switch (three)
	{
	case(0):
		printf("Three does not appear.\n");
		break;
	case(1):
		printf("Three appears one time.\n");
		break;
	case(2):
		printf("Three appears two times.\n");
		break;
	default:
		printf("The number three appears more than two times.\n");
		break;
	 }
	system("pause");
	return 0;
}
