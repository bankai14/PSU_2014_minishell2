##
## Makefile for  in /home/zitouni/rendu/shell2
## 
## Made by Yassine Zitouni
## Login   <zitoun_y@epitech.net>
## 
## Started on  Fri May  1 15:45:33 2015 Yassine Zitouni
## Last update Tue May 19 15:01:14 2015 Yassine Zitouni
##

CC	=	gcc  -g

RM	=	rm -f

CFLAGS +=	-I./include

NAME	=	mysh

SRCS	=	main.c					\
		process/redirection.c			\
		builtins/my_builtins.c			\
		parsing/liste_input.c			\
		builtins/cd.c				\
		parsing/write2.c			\
		builtins/unsetenv.c			\
		parsing/liste_env.c                     \
		parsing/write.c				\
		parsing/my_str_to_wordtab.c		\
		parsing/my_str_to_wordtab_2.c           \
		parsing/my_str_to_wordtab3.c		\
		process/exec.c				\
		parsing/get_next_line.c			\

OBJS	=	$(SRCS:.c=.o)


all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:	fclean all

ice_tee :	fclean all
		$(RM) *~ *#

.PHONY:		all clean fclean re

