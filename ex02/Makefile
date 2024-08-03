NAME	= main
SRCS	= main.cpp
OBJS	= $(SRCS:.cpp=.o)
CC	= c++
CPPFLAGS= -Wall -Werror -Wextra -std=c++98 #-g
RM	= rm -f

all:	$(NAME)

$(NAME):$(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o:%.cpp
	$(CC) -c $(CPPFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
