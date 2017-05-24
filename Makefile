CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = ft_select
HEADERS = $(wildcard includes/*.h$)
SRCS = $(wildcard srcs/*.c$)
OBJS = $(subst srcs/,.objs/,$(SRCS:.c=.o))
LIBFT = libft/libft.a
LIB_DEPS = $(wildcard libft/*.c$)

TO_LINK = ft termcap
LINK = -L libft $(foreach lib,$(TO_LINK), -l$(lib))

all : $(NAME)

$(NAME) : $(OBJS) $(HEADERS) $(LIBFT)
	$(CC) $(CFLAGS) $(LINK) .objs/*.o -o $@

$(OBJS) : $(SRCS) $(HEADERS) $(LIBFT)
	$(CC) $(CFLAGS) -Iincludes -c $(addprefix srcs/,$(subst .o,.c, $(notdir $@))) -o $@

$(LIBFT) : $(LIB_DEPS)
	make -C libft

.PHONY : clean fclean re print

print :
	@for file in $(basename $(notdir $(SRCS))); do \
		echo $$file ; \
	done

clean :
	@rm -Rf $(NAME).dSYM;
	@rm -f libft/*\.o$;
	@rm -f .objs/*\.o$;

fclean : clean
	@rm -f $(LIBFT)
	@rm -f $(NAME)

re : fclean all
