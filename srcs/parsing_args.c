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

int	initialization(t_deadly *table, int argc, char **argv)
{
	int	i;

	table->philo_count = ft_atoi(argv[1]);
	table->forks_count = table->philo_count;
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->eat_limit = -1;
	if (argc == 6)
		table->eat_limit = ft_atoi(argv[5]);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->forks_count);
	table->philos = malloc(sizeof(t_philo) * table->philo_count);
	if (err_msg(!table->forks || !table->philos, "Malloc error!"))
		return (1);
	i = -1;
	while (++i < table->philo_count)
	{
		table->philos[i].left = &table->forks[i];
		// if (philo_num == 1)
		if (i == 0)
			table->philos[i].right = &table->forks[table->forks_count - 1];
		else
			table->philos[i].right = &table->forks[i - 1];

	}
	return (0);
}
