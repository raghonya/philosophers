#include <philo.h>

int	clear_mutexes(t_deadly *table, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		pthread_mutex_destroy(&table->forks[i]);
	return (1);
}

int	init_mutexes(t_deadly *table)
{
	int	i;

	i = -1;
	while (++i < table->forks_count)
		if (err_msg(pthread_mutex_init(&table->forks[i], NULL), "Mutex error"))
			return (clear_mutexes(table, i));
	return (0);
}
