NAME	=	philo

CFLAGS	=	-Wall -Wextra -Werror -pthread

fa		=	-fsanitize=address -g
ft		=	#-fsanitize=thread  -g

DEP		=	Makefile includes/philo.h

OBJDIR	=	obj

SRCSDIR	=	srcs

SRCS	=	srcs/philo.c \
			srcs/ft_atoi.c \
			srcs/endless_eat.c 

OBJS	=	obj/philo.o \
			obj/ft_atoi.o \
			obj/endless_eat.o

IFLAGS	=	-Iincludes

all: objdir $(NAME)

objdir:
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCSDIR)/%.c $(DEP)
	$(CC) $(CFLAGS) $(fa) $(ft) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(fa) $(ft) $(IFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
