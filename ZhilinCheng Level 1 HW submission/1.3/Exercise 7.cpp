#include <stdio.h>
#include<Windows.h>
int main()
{
	int inputNumber;
	int n;
	printf("Please input an integer\n");
	scanf_s("%d", &inputNumber);
	printf("please input another integer\n");
	scanf_s("%d", &n);
	for (int i = 2; i < n; i++)
	{
		inputNumber = inputNumber << i;
		
	}
	printf("here is the answer\n%d", inputNumber);
	system("pause");
}