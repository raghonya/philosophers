/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_alive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:34:23 by raghonya          #+#    #+#             */
/*   Updated: 2023/06/30 17:34:24 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	check_philos_alive(t_deadly *table)
{
	pthread_mutex_lock(&table->eat_mutex);
	if (table->philos[0].eat_count)
		return (0);
	pthread_mutex_unlock(&table->eat_mutex);
	return (1);
}