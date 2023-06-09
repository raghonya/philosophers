#include <philo.h>

int	gluttonous_philos(t_deadly *philo)
{
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->forks_count);
	if (!philo->forks)
		return (1);
	
	return (0);
}