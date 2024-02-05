#include "ft_printf.h"

//Print uppercase hexadecimals and returns the count.
int	ft_puthex_upper(unsigned int nb, int fd)
{
	int		temp;
	int		i;
	int		hex_len;
	char	hex[100];

	i = 0;
	if (nb == 0)
		return (ft_putchar('0', 1));
	while (nb != 0)
	{
		temp = nb % 16;
		if (temp < 10)
			hex[i] = temp + 48;
		else
			hex[i] = temp + 55;
		nb /= 16;
		i++;
	}
	hex[i] = '\0';
	hex_len = ft_strlen(hex);
	while (hex_len > 0)
		ft_putchar(hex[--hex_len], fd);
	return (i);
}

//Print lowercase hexadecimals and also it can be used to print
//the address of a pointer. Returns the count.
int	ft_puthex_lower(unsigned int nb, int fd)
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
		temp = nb % 16;
		if (temp < 10)
			hex[i] = temp + 48;
		else
			hex[i] = temp + 87;
		nb /= 16;
		i++;
	}
	hex[i] = '\0';
	hex_len = ft_strlen(hex);
	while (hex_len > 0)
		ft_putchar(hex[--hex_len], fd);
	return (i);
}

int	ft_puthex_addr(unsigned long int nb, int fd)
{
	unsigned long int	temp;
	unsigned int		i;
	unsigned int		hex_len;
	char				hex[100];

	i = 0;
	if (nb == 0)
		return (ft_putchar('0', 1));
	while (nb != 0)
	{
		temp = nb % 16;
		if (temp < 10)
			hex[i] = temp + 48;
		else
			hex[i] = temp + 87;
		nb /= 16;
		i++;
	}
	hex[i] = '\0';
	hex_len = ft_strlen(hex);
	while (hex_len > 0)
		ft_putchar(hex[--hex_len], fd);
	return (i);
}