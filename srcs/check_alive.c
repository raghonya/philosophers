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
	int	havayi;
	int	count;
	int	i;

	i = -1;
	count = 0;
	if (table->eat_limit != -1)
	{
		while (++i < table->philo_count)
		{
			pthread_mutex_lock (table->philos[i].eat_mutex);
			havayi = table->philos[i].eat_count;
			pthread_mutex_unlock (table->philos[i].eat_mutex);
			if (havayi >= table->eat_limit)
				count++;
		}
	}
	if (count == table->philo_count)
	{
		clear_mutexes(table, table->forks_count);
		free(table->forks);
		free(table->philos);
		return (1);
	}
	i = -1;
	while (++i < table->philo_count)
	{
		pthread_mutex_lock(&table->die_mutex);
		if (cur_time(0) - table->philos[i].last_eat > table->time_to_die)
		{
			printf ("[%lld ms] %d died\n", cur_time(table->philos[i].startime), table->philos[i].id);
			clear_mutexes(table, table->forks_count);
			free(table->forks);
			free(table->philos);
			pthread_mutex_unlock(&table->die_mutex);
			return (1);
		}
		pthread_mutex_unlock(&table->die_mutex);
	}
	return (0);
}
