#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int		fd;
	char	*line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	line = NULL;
	while ((line = get_next_line(fd)))
	{
		printf("%s\n", line);
		free(line);
	}
	free(line);
	close(fd);
}