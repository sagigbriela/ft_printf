#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(char const *format, ...);
int	ft_putchar(char str, int fd);
int	ft_putstr(char *str, int fd);
int	print_characters(int fd, ...);
int	print_str(char const *format, ...);
int	print_ints(int fd, ...);
int	ft_putnbr(int n, int fd);
int	print_hex(int i, char const *format, ...);
int	ft_puthex_upper(unsigned long int nb, int fd);
int	ft_puthex_lower(unsigned long int nb, int fd);
int	ft_putaddr(int fd, ...);

#endif