#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_deadly
{
	int					forks_count;
	int					philo_count;
	pthread_mutex_t		*forks;

}	t_deadly;

int	ft_atoi(const char *s);
int	gluttonous_philos(t_deadly *philo);


#endif