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

void	print_step(t_philo *philo, char *msg)
{
	if (!is_dead(philo))
		printf ("[%lld ms] %d %s\n", \
		cur_time(philo->startime), philo->id, msg);
}

void	take_forks(t_philo *philo, pthread_mutex_t *first, \
	pthread_mutex_t *second)
{
	pthread_mutex_lock (first);
	if (philo->id % 2 == 0)
		print_step (philo, "has taken a right fork");
	else
		print_step(philo, "has taken a left fork");
	pthread_mutex_lock (second);
	if (philo->id % 2 == 0)
		print_step (philo, "has taken a left fork");
	else
		print_step(philo, "has taken a right fork");
	pthread_mutex_lock (&philo->end_mutex);
	philo->last_eat = cur_time(0);
	pthread_mutex_unlock (&philo->end_mutex);
	print_step(philo, "is eating");
	my_usleep(philo, cur_time(0), philo->time_to_eat);
	pthread_mutex_unlock (second);
	pthread_mutex_unlock (first);
}

void	*thread_handler(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while (!is_dead(philo))
	{
		if (philo->id % 2 == 0)
			take_forks(philo, philo->right, philo->left);
		else
			take_forks(philo, philo->left, philo->right);
		pthread_mutex_lock (&philo->eat_mutex);
			philo->eat_count++;
		pthread_mutex_unlock (&philo->eat_mutex);
		print_step (philo, "is sleeping");
		my_usleep(philo, cur_time(0), philo->time_to_sleep);
		print_step (philo, "is thinking");
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
			if (pthread_create(&table->philos[i].philo, NULL, \
			&thread_handler, &table->philos[i]))
				return (1);
	}
	return (0);
}
