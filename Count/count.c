#include<stdio.h>
#include<string.h>

int CountWord(char *s)
{
	int count = 0;
	int t = 0;
	char *pa;
	pa = s;
	while (*pa != '\0')
	{
		if (*pa == ' ')
		{
			t = 0;
		}
		else
		{
			if (t == 0)
			{
				t = 1;
				count++;
			}
		}
		pa++;
	}
	return count;
}

int CountC(char *s)
{
	int count = 0;
	char *pa;
	pa = s;

	while (*pa != '\0')
	{
		count++;
		pa++;
	}
	return count;
}

int main(int argc, char *argv[])
{
	char str[100] = { 0 };

	if (argc > 2)
	{
		FILE *pfile = fopen(argv[2], "r");
		if (pfile)
		{
			fread(str, sizeof(char), 100, pfile);
		}
		fclose(pfile);
		if (!strcmp(argv[1],"-w"))
		{
			printf("%d",CountWord(str));
		}
		if (!strcmp(argv[1], "-c"))
		{
			printf("%d", CountC(str));
		}
	}

	return 0;
}