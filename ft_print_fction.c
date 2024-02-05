#include "ft_printf.h"

//Print only one character.
int	print_characters(int fd, ...)
{
	va_list	ap;

	va_start(ap, fd);
	return (ft_putchar(va_arg(ap, int), fd));
}

//Print a string.
int	print_str(char const *format, ...)
{
	va_list	ap;
	int		str_len;

	va_start(ap, format);
	str_len = ft_putstr(va_arg(ap, char *), 1);
	return (str_len);
}

//Print integers or decimal.
int	print_ints(int fd, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, fd);
	count = ft_putnbr(va_arg(ap, int), fd);
	return (count);
}

//Print uppercase and lowercase hexadecimal.
int	print_hex(int i, char const *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	if (format[i + 1] == 'u')
		count = ft_putunsigned(va_arg(ap, int), 1);
	else if (format[i + 1] == 'X')
		count = ft_puthex_upper(va_arg(ap, int), 1);
	else
		count = ft_puthex_lower(va_arg(ap, int), 1);
	return (count);
}

//Print the address of a pointer.
int	ft_putaddr(int fd, ...)
{
	unsigned long int	p;
	va_list				ap;
	int					count;

	va_start(ap, fd);
	p = va_arg(ap, unsigned long int);
	count = 0;
	count += ft_putstr("0x", fd);
	count += ft_puthex_addr(p, fd);
	return (count);
}