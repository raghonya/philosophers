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
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_deadly	philo;

	if (argc != 5 && argc != 6)
		return (1);
	if (parsing_args(argv) || initialization(&philo, argc, argv))
		return (1);
	gluttonous_philos(&philo);
	return (0);
}
