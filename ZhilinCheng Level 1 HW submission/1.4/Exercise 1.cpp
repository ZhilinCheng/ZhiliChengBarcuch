#include <stdio.h>
#include <windows.h>
int main()
{
	int c = 0;

	int num_words = 0, num_chars = 0, num_newlines = 0;


	while (c != 4)
	{
		c = getchar();

		num_chars++;
 		if (c == 32)
		{
			num_words++;

		}
		if (c == 10)
		{
			num_newlines++;
		}


	}
	num_chars = num_chars - 1;
	printf("Number of Characters: %d", num_chars);
	printf("Number of words: %d", num_words);
	printf("Number of newlines: %d", num_newlines);
	system("pause");

	return 0;

}

