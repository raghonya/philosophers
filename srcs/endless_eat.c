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

void	print_step(t_philo *philo, char *msg, int eat)
{
	pthread_mutex_lock(philo->left);
	printf ("%lld %d %s\n", philo->startime, philo->id, msg);
	if (eat)
		printf ("%lld %d is eating\n", philo->startime, philo->id);
	pthread_mutex_unlock(philo->left);
}

void	*thread_handler(void *param)
{
	t_philo	*philo;
	int		i;

	i = -1;
	philo = (t_philo *)param;
	while (1)
	{
		print_step(philo, "has taken a left fork", DONTEAT);
		print_step(philo, "has taken a right fork", EAT);
		printf ("%d\n", *philo->is_dead);
		if (*philo->is_dead)
			break ;
	}
	return (NULL);
}

int	gluttonous_philos(t_deadly *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_count)
	{
		table->philos[i].id = i + 1;
		if (table->philos[i].id % 2 == 0)
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
