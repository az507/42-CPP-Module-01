NAME	= sed
SRCS	= main.cpp
OBJS	= $(SRCS:.cpp=.o)
CC	= c++
CPPFLAGS= -Wall -Werror -Wextra -std=c++98 -g -MMD -MP
RM	= rm -f

all:	$(NAME)

asan:	CPPFLAGS += -g -fsanitize=address
asan:	fclean
asan:	$(NAME)


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
