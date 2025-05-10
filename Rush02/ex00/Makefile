NAME =	rush-02

SRC =	main.c  parsing1.c  parsing_find_adress_key.c  parsing_routine.c  parsing_utils.c  print_nb.c  print_utils.c

OBJ =	$(SRC:.c=.o)

INC =	rush02.h

CC =	cc
FLAGS =	-Wall -Wextra -Werror -g

RM = 	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o$@ $^

$(OBJ): %.o:	%.c	$(INC)
	$(CC) $(FLAGS) -c $< -o$@

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ) $(NAME)

re: fclean all

.PHONY: re fclean clean all $(CC) $(FLAGS) $(RM)
