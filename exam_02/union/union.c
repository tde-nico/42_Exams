#include <unistd.h>

int check(char *argv, char c, int i)
{
	while (i-- >= 0)
	{
		if (c == argv[i])
			return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 3)   // with or without "\n"
	{
		write(1, "\n", 1);
		return (1);
	}
	i = -1;
	while (argv[1][++i] != '\0')		
	{
		if (!(check(argv[1], argv[1][i], i)))
			write(1, &argv[1][i], 1);
	}
	j = -1;
	while (argv[2][++j] != '\0')		
	{
		if (!(check(argv[1], argv[2][j], i)) && !(check(argv[2], argv[2][j], j)))
			write(1, &argv[2][j], 1);
	}
	write(1, "\n", 1);
	return (0);
}