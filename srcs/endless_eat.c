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
		pthread_mutex_lock (philo->eat_mutex);
		if (*philo->is_dead || *philo->full_eat)
		{
			printf ("%drd philo, eat_radexi: %d\n", philo->id, *philo->full_eat);
			pthread_mutex_unlock (philo->eat_mutex);
			break ;
		}
		pthread_mutex_unlock (philo->eat_mutex);
		pthread_mutex_lock (philo->left);
			printf ("%lld %d has taken a left fork\n", cur_time(philo->startime), philo->id);
			pthread_mutex_lock (philo->right);
				printf ("%lld %d has taken a right fork\n", cur_time(philo->startime), philo->id);
				printf ("%lld %d is eating\n", cur_time(philo->startime), philo->id);
				my_usleep(philo, philo->time_to_eat);
			pthread_mutex_unlock (philo->right);
		pthread_mutex_unlock (philo->left);
		printf ("%lld %d is sleeping\n", cur_time(philo->startime), philo->id);
		
		pthread_mutex_lock (philo->eat_mutex);
		philo->eat_count++;
		pthread_mutex_unlock (philo->eat_mutex);
		
		my_usleep(philo, philo->time_to_sleep);
		printf ("%lld %d is thinking\n", cur_time(philo->startime), philo->id);
	}
	return (NULL);
}

int	gluttonous_philos(t_deadly *table)
{
	int	i;

	printf ("time to %s %d\n", "die", table->time_to_die);
	printf ("time to %s %d\n", "eat", table->time_to_eat);
	printf ("time to %s %d\n", "sleep", table->time_to_sleep);
	printf ("eat limit %d\n", table->eat_limit);
	i = -1;
	while (++i < table->philo_count)
	{
		table->philos[i].id = i + 1;
		// printf ("id ==== %d\n", table->philos[i].id);
		if (table->philos[i].id % 2 == 0)
		{
			// printf ("id in if dlya qnel ==== %d\n", table->philos[i].id);
			usleep(500);
			if (pthread_create(&table->philos[i].philo, NULL, \
			&thread_handler, &table->philos[i]))
				return (1);
		}
		else
		{
			// printf ("id in if ==== %d\n", table->philos[i].id);
			if (pthread_create(&table->philos[i].philo, NULL, \
			&thread_handler, &table->philos[i]))
				return (1);
		}
	}
	return (0);
}
