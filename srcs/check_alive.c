/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_alive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:34:23 by raghonya          #+#    #+#             */
/*   Updated: 2023/06/30 17:34:24 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	check_philos_alive(t_deadly *table)
{
	long long	count;
	int	i;

	i = -1;
	count = 0;
	if (table->eat_limit != -1)
	{
		while (++i < table->philo_count)
		{
			pthread_mutex_lock (&table->philos[i].eat_mutex);
			if (table->philos[i].eat_count >= table->eat_limit)
				count++;
			pthread_mutex_unlock (&table->philos[i].eat_mutex);
		}
	}
	if (count == table->philo_count)
	{
		// clear_mutexes(table, table->forks_count);
		// free(table->forks);
		// free(table->philos);
		return (1);
	}
	i = -1;
	while (++i < table->philo_count)
	{
		pthread_mutex_lock(&table->philos[i].end_mutex);
		count = table->philos[i].last_eat;
		pthread_mutex_unlock(&table->philos[i].end_mutex);
		if (cur_time(0) - count > table->time_to_die)
		{
			// print_step (&table->philos[i], "died");
			// printf ("in main: %p\n", &table->die_mutex);
			pthread_mutex_lock (table->philos[i].die_mutex);
			table->dead_ptr = 1;
			pthread_mutex_unlock (table->philos[i].die_mutex);
			printf ("[%lld ms] %d died\n", \
			cur_time(table->philos[i].startime), table->philos[i].id);
			// i = -1;
			// while(++i < table->philo_count)
			// 	pthread_mutex_lock(&table->philos[i].end_mutex);
			return (1);
		}
		// pthread_mutex_unlock(&table->philos[i].end_mutex);
	}
	return (0);
}
