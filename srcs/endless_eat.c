/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endless_eat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:28:50 by raghonya          #+#    #+#             */
/*   Updated: 2023/06/10 18:28:53 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*thread_handler(void *param)
{
	// t_deadly	*philo;
	int			i;

	i = -1;
	// philo = (t_deadly *)param;
	// pthread_mutex_lock(&philo->philo_num);
	// printf ("%d\n", philo->philo_num);
	// pthread_mutex_unlock(&philo->philo_num);
	// printf ("aaaa\n");

	return (NULL);
}

int	gluttonous_philos(t_deadly *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_count)
	{
		table->philos[i].id = i + 1;
		if (i % 2)
		{
			usleep(1000);
			if (pthread_create(&table->philos[i].philo, NULL, \
			&thread_handler, &table->philos[i]))
				return (1);
		}
		else
			if (pthread_create(&table->philos[i].philo, NULL, \
			&thread_handler, &table->philos[i]))
				return (1);
	}
	i = -1;
	while (++i < table->philo_count)
		pthread_join(table->philos[i].philo, NULL);
	return (0);
}
