#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char	set[5] = "<^>_";
	char	*output;

	output = (char *)malloc(sizeof(char) * 10 * 10 + 1);
	int i = 0;
	int ix = 0;
	int iy = 0;
	while (i < 100000)
	{
		iy = 0;
		while (iy < 10)
		{
			memset(output + (iy * 10), set[i % 4], 9);
			memset(output + (iy * 10) + 9, '\n', 1);
			iy++;
		}
		memset(output + 111, '\0', 1);
		fprintf(stderr, "\033[2J\033[2H");
		fprintf(stderr, "%s", output);
		usleep(200000);
		i++;
	}
	return (0);
}
