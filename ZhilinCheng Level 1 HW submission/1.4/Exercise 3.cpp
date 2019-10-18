#include <stdio.h>
#include <Windows.h>
int main()
{
	int c = 0;

	int num_words = 0, num_chars = 0, num_newlines = 0;
	while (c != 4)
	{
		c = getchar();
		num_chars++;

		switch (c)
		{
		case 4:
			break;
		case 32:
			num_words++;
			break;
		case 10:
			num_newlines++;
			break;
		default:
			break;
		}
	}
	num_chars = num_chars - 1;
	printf("Number of Characters: %d", num_chars);
		printf("Number of words: %d", num_words);
		printf("Number of newlines: %d", num_newlines);
		system("pause");
	}


