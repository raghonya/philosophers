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

int	is_dead(t_philo *philo)
{
	int	ret;

	pthread_mutex_lock (philo->die_mutex);
	ret = *philo->is_dead;
	pthread_mutex_unlock (philo->die_mutex);
	return (ret);
}

int	set_dead(t_deadly *table, int print, int i)
{
	if (print)
		printf ("[%lld ms] %d died\n", \
		cur_time(table->philos[i].startime), table->philos[i].id);
	pthread_mutex_lock (&table->die_mutex);
	table->dead_ptr = 1;
	pthread_mutex_unlock (&table->die_mutex);
	wait_threads (table);
	clear_mutexes(table, table->forks_count);
	return (1);
}

int	full_check(t_deadly *table)
{
	int	count;
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
		if (count == table->philo_count)
			return (set_dead(table, 0, 0));
	}
	return (0);
}

int	die_check(t_deadly *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_count)
	{
		pthread_mutex_lock(&table->philos[i].end_mutex);
		if (cur_time(0) - table->philos[i].last_eat > table->time_to_die)
		{
			pthread_mutex_unlock(&table->philos[i].end_mutex);
			return (set_dead(table, 1, i));
		}
		pthread_mutex_unlock(&table->philos[i].end_mutex);
	}
	return (0);
}
