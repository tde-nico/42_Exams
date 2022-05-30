#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	int	rd;
	int	i;
	char	c;
	char	buffer[9999999999];  //malloc(999999999)

	i = -1;
	while ((rd = read(fd, &c, BUFFER_SIZE * 0 + 1)) > 0)
	{
		buffer[++i] = c;
		if (c == '\n')
			break ;
	}
	if ((!buffer[i] && !rd) || rd == -1)      //free(buffer)
		return (NULL);
	buffer[i] = '\0';
	return (buffer);
}
