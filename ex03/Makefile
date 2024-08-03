NAME	= violence
SRCS	= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS	= $(SRCS:.cpp=.o)
CC	= c++
CPPFLAGS= -Wall -Werror -Wextra -std=c++98 -MMD -MP #-g
RM	= rm -f

all:	$(NAME)

asan:	CPPFLAGS += -g -fsanitize=address
asan:	fclean
asan:	$(NAME)


$(NAME):$(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o:%.cpp %.d
	$(CC) -c $(CPPFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
