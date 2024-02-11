NAME		= task2

SRC			= main.cpp AudioFileManipulation.cpp
OBJ			= $(SRC:.cpp=.o)
CC			= c++
RM			= rm -rf
#CPPFLAGS	= -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ) Makefile
			$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re