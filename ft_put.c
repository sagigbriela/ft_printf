#include "ft_printf.h"

//Print the character and returns the value (1)
int	ft_putchar(char str, int fd)
{
	write(fd, &str, 1);
	return (1);
}

//Print the string and returns the length of the String.
int	ft_putstr(char *str, int fd)
{
	int	count;

	count = 0;
	if (!str)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (str[count])
	{
		write(fd, &str[count], 1);
		count++;
	}
	return (count);
}

//Convert the int into array so it can be printed and counted.
void	convert_to_array(int n, char *ar, int *i)
{
	while (n > 0)
	{
		ar[(*i)++] = (n % 10) + '0';
		n /= 10;
	}
}

//Print the integers and returns the lenght of the array.
int	ft_putnbr(int n, int fd)
{
	char	ar[10];
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (n == 0)
		return (ft_putchar('0', fd));
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n *= -1;
		count += ft_putchar('-', fd);
	}
	convert_to_array(n, ar, &i);
	while (i > 0)
		count += ft_putchar(ar[--i], fd);
	return (count);
}

int	ft_putunsigned(unsigned int nb, int fd)
{
	int		temp;
	int		i;
	char	hex[100];
	int		hex_len;

	i = 0;
	if (nb == 0)
		return (ft_putchar('0', 1));
	while (nb != 0)
	{
		temp = nb % 10;
		hex[i] = temp + 48;
		nb /= 10;
		i++;
	}
	hex[i] = '\0';
	hex_len = ft_strlen(hex);
	while (hex_len > 0)
		ft_putchar(hex[--hex_len], fd);
	return (i);
}