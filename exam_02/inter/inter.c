#include <unistd.h>

int	check(char *str, char c, int i)
{
	while (--i >= 0)
		if (str[i] == c)
			return 1;
	return 0;
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	if (argc != 3)
		return (1);
	i = -1;
	while (argv[1][++i])
	{
		j = -1;
		while (argv[2][++j])
		{
			if ((argv[1][i] == argv[2][j]) && !check(argv[1], argv[1][i], i))
			{
				write(1, &argv[1][i], 1);
				break;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}