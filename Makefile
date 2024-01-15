NAME = libftprintf.a
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFTDIR = ./libft

SRCS = ft_printf.c ft_parse_format.c  ft_print_char.c ft_print_str.c ft_print_d_i.c ft_print_u.c ft_print_p.c\
		ft_itoa_nosigne.c ft_itoa_unsigned.c ft_itoa_base_16.c ft_print_x_X.c  ft_itoa_p.c
 
OBJS = $(SRCS:.c=.o)

HEADERS = ft_printf.h

all: $(NAME)

bonus : $(NAME)

makelibft:
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTNAME) ./$(NAME)

$(NAME): makelibft $(OBJS)
	ar rc $(NAME) $(OBJS)
	
%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

test: $(NAME) main.c
	$(CC) main.c -L. -l ftprintf
	./a.out

clean:
	rm -f $(OBJS)
	cd $(LIBFTDIR) && make clean
	
fclean: clean
	rm -f $(NAME)
	cd $(LIBFTDIR) && make fclean
	
re: fclean all

.PHONY : all clean fclean re
