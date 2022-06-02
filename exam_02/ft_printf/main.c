#include <stdio.h>

int ft_printf(char *str, ...);

int main(void)
{
	char *str = NULL;
	printf("\n\nTEST %%s\n\n");
	printf("\n___TEST %%s___\n");
	printf("No original - %d\n", ft_printf("|%s|\n", str));
	printf("Original - %d\n", printf("|%s|\n", str));

	printf("\n___TEST %%ss___\n");
	printf("No original - %d\n", ft_printf("|%ss|\n", str));
	printf("Original - %d\n", printf("|%ss|\n", str));

	printf("\n___TEST test___\n");
	printf("No original - %d\n", ft_printf("|%ss|\n", "test"));
	printf("Original - %d\n", printf("|%ss|\n", "test"));



	printf("\n\nTEST %%d\n\n");
	int num = 0;
	printf("\n___TEST %%d___\n");
	printf("No original - %d\n", ft_printf("|%d|\n", num));
	printf("Original - %d\n", printf("|%d|\n", num));

	printf("\n___TEST %%dd___\n");
	printf("No original - %d\n", ft_printf("|%dd|\n", num));
	printf("Original - %d\n", printf("|%dd|\n", num));

	printf("\n___TEST min_int___\n");
	printf("No original - %d\n", ft_printf("|%d|\n", -2147483648));
	printf("Original - %d\n", printf("|%ld|\n", -2147483648));

	printf("\n___TEST max_int___\n");
	printf("No original - %d\n", ft_printf("|%d|\n", 2147483647));
	printf("Original - %d\n", printf("|%d|\n", 2147483647));


	printf("\n\nTEST %%x\n\n");
	unsigned int un = 0;
	printf("\n___TEST %%x___\n");
	printf("No original - %d\n", ft_printf("|%x|\n", un));
	printf("Original - %d\n", printf("|%x|\n", un));

	printf("\n___TEST %%xx___\n");
	printf("No original - %d\n", ft_printf("|%xx|\n", un));
	printf("Original - %d\n", printf("|%xx|\n", un));

	printf("\n___TEST int___\n");
	printf("No original - %d\n", ft_printf("|%x|\n", 2147483647));
	printf("Original - %d\n", printf("|%x|\n", 2147483647));

	return (0);
}
