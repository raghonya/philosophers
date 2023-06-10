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
	t_deadly	*philo;
	int			i;

	i = -1;
	philo = (t_deadly *)param;
	
	// printf ("aaaa\n");

	return (philo);
}

int	gluttonous_philos(t_deadly *philo)
{
	int	i;

	i = -1;
	philo->philos = malloc(sizeof(pthread_t) * philo->philo_count);
	if (err_msg(!philo->philos, "Malloc error\n"))
		return (1);
	while (++i < philo->philo_count)
	{
		if (i % 2)
			usleep(10);
		pthread_create(&philo->philos[i], NULL, \
		&thread_handler, philo);
	}
	i = -1;
	while (++i < philo->philo_count)
		pthread_join(philo->philos[i], NULL);
	return (0);
}
