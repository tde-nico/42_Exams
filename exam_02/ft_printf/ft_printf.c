#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(unsigned int n, int base)
{
	int	i;

	i = 0;
	if (n > (unsigned int)base)
		i += ft_putnbr(n / base, base);
	return (i + write(1, &"0123456789abcdef"[n % base], 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = -1;
	if (!str)
		str = "(null)";
	while (str[++i])
		ft_putchar(str[i]);
	return (i);
}

int	ft_putint(int n)
{
	int		count;
	long	num;

	count = 0;
	num = (long)n;
	if (num < 0)
	{
		count += ft_putchar('-');
		num *= -1;
	}
	count += ft_putnbr(num, 10);
	return (count);
}

int	ft_printf(char *str, ...)
{
	int		count;
	va_list	args;
	int		i;

	i = -1;
	count = 0;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
				count += ft_putstr(va_arg(args, char *));
			if (str[i] == 'd')
				count += ft_putint(va_arg(args, int));
			if (str[i] == 'x')
				count += ft_putnbr(va_arg(args, unsigned int), 16);
		}
		else
			count += ft_putchar(str[i]);
	}
	va_end(args);
	return (count);
}