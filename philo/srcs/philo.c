/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:29:19 by raghonya          #+#    #+#             */
/*   Updated: 2023/06/10 18:29:20 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	err_msg(int condition, char *msg)
{
	if (condition)
	{
		write (2, msg, ft_strlen(msg));
		write (2, "\n", 1);
		return (1);
	}
	return (0);
}

void	wait_threads(t_deadly *table)
{
	int	i;

	i = -1;
	if (table->philo_count > 1)
		while (++i < table->philo_count)
			pthread_join(table->philos[i].philo, NULL);
}

int	main(int argc, char **argv)
{
	t_deadly	table;

	if (err_msg (argc != 5 && argc != 6, "Give at least 5 arguments") \
		|| parsing_args(argv) || initialization(&table, argc, argv) \
		|| gluttonous_philos(&table))
		return (1);
	while (1)
		if (full_check(&table) || die_check(&table))
			return (0);
}
