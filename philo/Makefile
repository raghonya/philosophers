NAME	=	philo

CFLAGS	=	-pthread -Wall -Wextra -Werror

DEP		=	Makefile includes/philo.h

OBJDIR	=	obj

SRCSDIR	=	srcs

SRCS	=	srcs/philo.c \
			srcs/mutexes.c \
			srcs/ft_strlen.c \
			srcs/ft_isdigit.c \
			srcs/ft_atoi.c \
			srcs/check_alive.c \
			srcs/endless_eat.c \
			srcs/parsing_args.c \
			srcs/time_features.c

OBJS	=	obj/philo.o \
			obj/mutexes.o \
			obj/ft_strlen.o \
			obj/ft_isdigit.o \
			obj/ft_atoi.o \
			obj/check_alive.o \
			obj/endless_eat.o \
			obj/parsing_args.o \
			obj/time_features.o

IFLAGS	=	-Iincludes

all:	objdir $(NAME)

objdir:
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:	$(SRCSDIR)/%.c $(DEP)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
