/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   homemade_usleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:34:12 by raghonya          #+#    #+#             */
/*   Updated: 2023/06/30 17:34:32 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

long long	cur_time(long long start)
{
	struct timeval	time;
	long long		time_ms;

	gettimeofday (&time, NULL);
	time_ms = (time.tv_sec) * 1000 \
		+ (time.tv_usec) / 1000;
	return (time_ms - start);
}

void	my_usleep(t_philo *philo, long long startime, long long time_to)
{
	while (cur_time(0) - startime < time_to && !is_dead(philo))
		usleep(50);
}
