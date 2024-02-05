#include "ft_printf.h"

//Proceso para dirigir al tipo de variable requerido.
int	process_format(const char *format, va_list ap, int *i)
{
	int	count;

	count = 0;
	if (!format || !ap)
		return (-1);
	if (format[*i] != 37)
		count += ft_putchar(format[(*i)++], 1);
	else
	{
		if (format[*i + 1] == 'c')
			count += print_characters(1, va_arg(ap, int));
		else if (format[*i + 1] == 's')
			count += print_str(format, va_arg(ap, char *));
		else if (format[*i + 1] == 'd' || format[*i + 1] == 'i')
			count += print_ints(1, va_arg(ap, int));
		else if (format[*i + 1] == 'X' || format[*i + 1] == 'x'
			|| format[*i + 1] == 'u')
			count += print_hex(*i, format, va_arg(ap, unsigned int));
		else if (format[*i + 1] == 'p')
			count += ft_putaddr(1, va_arg(ap, unsigned long int));
		else if (format[*i] == 37 && format[*i + 1] == 37)
			count += ft_putchar('%', 1);
		*i += 2;
	}
	return (count);
}

//Función principal.
int	ft_printf(char const *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	if (write(1, "", 0) == -1)
		return (-1);
	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		count += process_format(format, ap, &i);
	}
	va_end(ap);
	return (count);
}