NAME = libftprintf.a
LIBFTNAME = libft.a
LIBFTDIR = ./libft

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	./ft_printf.c ./ft_put.c . /ft_print_fction.c ./ft_puthex.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJS)
	@ar -r $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)
	@cd $(LIBFTDIR) && make clean
	
fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean
	
re: fclean all