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

// void	print_step(t_philo *philo, pthread_mutex_t *fork, char *msg, int eat)
// {
// 	// pthread_mutex_lock(fork_l);
// 		// pthread_mutex_lock(fork_r);
// 			// uslee(1232); // hac em utum kam es shat gidem inch
// 		// pthread_mutex_unlock(fork_r);
// 	// pthread_mutex_unlock(fork_l);
// 	pthread_mutex_lock(fork);
// 	printf ("%lld %d %s\n", philo->startime, philo->id, msg);
// 	if (eat)
// 	{
// 		printf ("%lld %d is eating\n", philo->startime, philo->id);
// 		my_usleep(philo, philo->time_to_eat);
// 	}
// 	pthread_mutex_unlock(fork);
// }

void	*thread_handler(void *param)
{
	t_philo	*philo;
	int		i;

	i = -1;
	philo = (t_philo *)param;
	while (1)
	{
		pthread_mutex_lock (philo->left);
			printf ("%lld %d has taken a left fork\n", cur_time(philo->startime), philo->id);
			pthread_mutex_lock (philo->right);
				printf ("%lld %d has taken a right fork\n", cur_time(philo->startime), philo->id);
				my_usleep(philo, philo->time_to_eat);
			pthread_mutex_unlock (philo->right);
		pthread_mutex_unlock (philo->left);
		printf ("%lld %d is sleeping\n", cur_time(philo->startime), philo->id);
		my_usleep(philo, philo->time_to_sleep);
		printf ("%lld %d is thinking\n", cur_time(philo->startime), philo->id);
		if (*philo->is_dead || philo->eat_count > 5)
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
	return (0);
}
