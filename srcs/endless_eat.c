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

int	print_step(t_philo *philo, char *msg)
{
	// printf ("in thread: %p\n", philo->die_mutex);
	pthread_mutex_lock (philo->die_mutex);
	if (*philo->is_dead)
	{
		pthread_mutex_unlock (philo->die_mutex);
		return (1);
	}
	printf ("[%lld ms] %d %s\n", cur_time(philo->startime), philo->id, msg);
	pthread_mutex_unlock (philo->die_mutex);
	return (0);
}

int	take_forks(t_philo *philo, pthread_mutex_t *first, pthread_mutex_t *second)
{
	pthread_mutex_lock (first);
		
		if ((philo->id % 2 == 0 && print_step(philo, "has taken a right fork")) \
		|| (philo->id % 2 == 1 && print_step(philo, "has taken a left fork")))
			return (1);
		// else if (philo->id % 2 == 1 && print_step(philo, "has taken a right fork"))
			// print_step(philo, "has taken a left fork");
		
		pthread_mutex_lock (second);
		if ((philo->id % 2 == 0 && print_step(philo, "has taken left fork")) \
		|| (philo->id % 2 == 1 && print_step(philo, "has taken a right fork")))
			return (1);
		// else if (philo->id % 2 == 1 && print_step(philo, "has taken a right fork"))
			// return (1);
			// print_step(philo, "has taken a left fork");
			if (print_step(philo, "is eating"))
				return (1);

			my_usleep(cur_time(0), philo->time_to_eat);
		
			pthread_mutex_lock (&philo->end_mutex);
				philo->last_eat = cur_time(0);
			pthread_mutex_unlock (&philo->end_mutex);
		
		pthread_mutex_unlock (second);
	pthread_mutex_unlock (first);
	return (0);
}

void	*thread_handler(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while (1)
	{
		if ((philo->id % 2 == 0 && take_forks(philo, philo->right, philo->left)) \
		|| (philo->id % 2 == 1 && take_forks(philo, philo->left, philo->right)))
			return (NULL);
			// take_forks(philo, philo->right, philo->left);
		// else
			// take_forks(philo, philo->left, philo->right);
		if (print_step (philo, "is sleeping"))
			return (NULL);
		// printf ("[%lld ms] %d is sleeping\n", cur_time(philo->startime), philo->id);
		
		my_usleep(cur_time(0), philo->time_to_sleep);
		
		// EAT COUNT LOCK
		pthread_mutex_lock (&philo->eat_mutex);
			philo->eat_count++;
		pthread_mutex_unlock (&philo->eat_mutex);
		// EAT COUNT UNLOCK

		if (print_step (philo, "is thinking"))
			return (NULL);
		// printf ("[%lld ms] %d is thinking\n", cur_time(philo->startime), philo->id);
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
		// pthread_detach(table->philos[i].philo);
	}
	return (0);
}
