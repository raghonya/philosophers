/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:34:17 by raghonya          #+#    #+#             */
/*   Updated: 2023/06/30 17:34:18 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	clear_mutexes(t_deadly *table, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		pthread_mutex_destroy(&table->forks[i]);
	pthread_mutex_destroy(&table->die_mutex);
	pthread_mutex_destroy(&table->eat_mutex);
	return (1);
}

int	init_mutexes(t_deadly *table)
{
	int	i;

	i = -1;
	if (err_msg(pthread_mutex_init(&table->eat_mutex, NULL) || \
		pthread_mutex_init(&table->die_mutex, NULL), "Mutex error"))
		return (1);
	while (++i < table->forks_count)
		if (err_msg(pthread_mutex_init(&table->forks[i], NULL), "Mutex error"))
			return (clear_mutexes(table, i));
	return (0);
}
