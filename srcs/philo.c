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
		write (1, msg, ft_strlen(msg));
		write (1, "\n", 1);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_deadly	table;

	if ((argc != 5 && argc != 6) || parsing_args(argv) || \
		initialization(&table, argc, argv))
		return (1);
	gluttonous_philos(&table);
	return (0);
}
