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

void	take_forks(t_philo *philo, pthread_mutex_t *first, pthread_mutex_t *second)
{
	pthread_mutex_lock (first);
	if (philo->id % 2 == 0)
		printf ("[%lld ms] %d has taken a right fork\n", cur_time(philo->startime), philo->id);
	else
	printf ("[%lld ms] %d has taken a left fork\n", cur_time(philo->startime), philo->id);
	pthread_mutex_lock (second);
	if (philo->id % 2 == 0)
		printf ("[%lld ms] %d has taken a left fork\n", cur_time(philo->startime), philo->id);
	else
		printf ("[%lld ms] %d has taken a right fork\n", cur_time(philo->startime), philo->id);
	printf ("[%lld ms] %d is eating\n", cur_time(philo->startime), philo->id);
	my_usleep(philo, cur_time(0), philo->time_to_eat);
		pthread_mutex_lock (philo->die_mutex);
		philo->last_eat = cur_time(0);
		pthread_mutex_unlock (philo->die_mutex);
	pthread_mutex_unlock (second);
	pthread_mutex_unlock (first);
}

void	*thread_handler(void *param)
{
	t_philo	*philo;
	int		i;

	i = -1;
	philo = (t_philo *)param;
	while (1)
	{
		if (philo->id % 2 == 0)
			take_forks(philo, philo->right, philo->left);
		else
			take_forks(philo, philo->left, philo->right);
		printf ("[%lld ms] %d is sleeping\n", cur_time(philo->startime), philo->id);
		my_usleep(philo, cur_time(0), philo->time_to_sleep);
		
		// EAT COUNT LOCK
		pthread_mutex_lock (philo->eat_mutex);
		philo->eat_count++;
		pthread_mutex_unlock (philo->eat_mutex);
		// EAT COUNT UNLOCK
		
		printf ("[%lld ms] %d is thinking\n", cur_time(philo->startime), philo->id);
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
			usleep(100);
			if (pthread_create(&table->philos[i].philo, NULL, \
			&thread_handler, &table->philos[i]))
				return (1);
		}
		else
		{
			if (pthread_create(&table->philos[i].philo, NULL, \
			&thread_handler, &table->philos[i]))
				return (1);
		}
	}
	return (0);
}
