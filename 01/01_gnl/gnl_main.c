#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main(int ac, char *av[])
{
	int fd[256];
	char *line;
/*
	fd[0] = open(0, O_RDONLY);
	line = malloc(1);
	while (line)
	{
		free(line);
		line = get_next_line(0);
		printf("%s", line);
	}
	free(line);
*/

	fd[0] = open(ac[av - 1], O_RDONLY);
	line = malloc(1);
	while (line)
	{
		free(line);
		line = get_next_line(fd[0]);
		printf("%s", line);
	}
	free(line);

/*
	fd[0] = open(av[1], O_RDONLY);
	fd[1] = open(av[2], O_RDONLY);
	fd[2] = open(av[3], O_RDONLY);

	int flag[3];
	flag[0] = 1;
	flag[1] = 1;
	flag[2] = 1;

	char *lines[3];
	lines[0] = malloc(1);
	lines[1] = malloc(1);
	lines[2] = malloc(1);

	while (flag[0] || flag[1] || flag[2])
	{
		if (flag[0])
		{
			free(lines[0]);
			lines[0] = get_next_line(fd[0]);
			if (lines[0] == NULL)
				flag[0] = 0;	
			printf("%s", lines[0]);
		}



		if (flag[1])
		{
			free(lines[1]);
			lines[1] = get_next_line(fd[1]);
			if (lines[1] == NULL)
				flag[1] = 0;
			printf("%s", lines[1]);
		}

		if (flag[2])
		{
			free(lines[2]);
			lines[2] = get_next_line(fd[2]);
			if (lines[2] == NULL)
				flag[2] = 0;
			printf("%s", lines[2]);
		}
	}
*/
	return (0);
}
