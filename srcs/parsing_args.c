/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:29:14 by raghonya          #+#    #+#             */
/*   Updated: 2023/06/10 18:29:15 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	parsing_args(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		if (err_msg (*argv[i] == '-', "Give normal arguments bro🌚\n"))
			return (1);
		while (argv[i][++j])
			if (err_msg(!ft_isdigit(argv[i][j]), "Non numeric arguments\n"))
				return (1);
	}
	return (0);
}

int	initialization(t_deadly *philo, int argc, char **argv)
{
	philo->philo_count = ft_atoi(argv[1]);
	philo->forks_count = philo->philo_count;
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->eat_limit = -1;
	if (argc == 6)
		philo->eat_limit = ft_atoi(argv[5]);
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->forks_count);
	if (!philo->forks)
		return (1);
	return (0);
}
