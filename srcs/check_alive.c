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
	int	count;
	int	i;

	i = -1;
	count = 0;
	if (table->eat_limit != -1)
	{
		while (++i < table->philo_count)
		{
			pthread_mutex_lock (&table->eat_mutex);
			// printf ("eatcnt: %d, eatlmt: %d\n", table->philos[i].eat_count, table->eat_limit);
			if (table->philos[i].eat_count >= table->eat_limit)
				count++;
			pthread_mutex_unlock (&table->eat_mutex);
		}
	}
	if (count == table->philo_count)
	{
		pthread_mutex_lock (&table->eat_mutex);
		table->eat_ptr = 1;
		pthread_mutex_unlock (&table->eat_mutex);
		return (0);
	}
	return (1);
}
