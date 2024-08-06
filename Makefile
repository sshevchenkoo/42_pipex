NAME = pipex.a
PRINTFNAME = libftprintf.a
CC = cc
CFLAGS = -g -Wall -Werror -Wextra
PRINTFDIR = ./libft_printf

SRCS = 	src/pipex.c src/child.c

OBJS = $(SRCS:.c=.o)

all: $(NAME) pipex

makelibft:
	@make -C $(PRINTFDIR)
	@cp $(PRINTFDIR)/$(PRINTFNAME) .
	@mv $(PRINTFNAME) $(NAME)

$(NAME): makelibft $(OBJS)
	@ar -r $(NAME) $(OBJS)

pipex: $(NAME)
	$(CC) $(CFLAGS) src/pipex.c $(NAME) -o pipex

clean:
	@rm -f $(OBJS)
	@cd $(PRINTFDIR) && make clean
	
fclean: clean
	@rm -f $(NAME) pipex
	@cd $(PRINTFDIR) && make fclean
	
re: fclean all

.PHONY: all re fclean clean
