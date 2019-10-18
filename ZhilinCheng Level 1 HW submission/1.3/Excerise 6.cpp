#include <stdio.h>
#include<Windows.h>
int main()
{
	int inputNumber, shiftedInputNumber;

	printf("Please input an integer\n");
	scanf_s("%d", &inputNumber);
	shiftedInputNumber = inputNumber >> 2;
 	printf("The shifted number is %d\n", shiftedInputNumber);
	system("pause");
}