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
	t_philo	*philo;
	int		i;

	i = -1;
	philo = (t_philo *)param;
	//printf ("%d, %p, %p\n", philo->id, philo->left, philo->right);
	pthread_mutex_lock(philo->right);
	gettimeofday(&philo->time, NULL);
	printf ("%d %d has taken right fork\n", philo->time.tv_usec, philo->id);
	pthread_mutex_unlock(philo->right);
	gettimeofday(&philo->time, NULL);
	pthread_mutex_lock(philo->left);
	printf ("%d %d has taken left fork\n", philo->time.tv_usec, philo->id);
	pthread_mutex_unlock(philo->left);
	

	return (NULL);
}

int	gluttonous_philos(t_deadly *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_count)
	{
		//printf ("bannn\n");
		table->philos[i].id = i + 1;
		if (i % 2)
		{
			usleep(10);
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
