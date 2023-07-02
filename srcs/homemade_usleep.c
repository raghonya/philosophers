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

void	my_usleep(t_philo *philo, long long startime, long long time_to)
{
	while (cur_time(0) - startime < time_to)
		usleep(50);
}
