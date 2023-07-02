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

void	init_args(t_deadly *table, int argc, char **argv)
{
	table->philo_count = ft_atoi(argv[1]);
	table->forks_count = table->philo_count;
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->eat_limit = -1;
	if (argc == 6)
		table->eat_limit = ft_atoi(argv[5]);
}

void	init_philos(t_deadly *table)
{
	int	i;

	i = -1;
	table->startime = cur_time(0);
	while (++i < table->philo_count)
	{
		table->philos[i].eat_count = 0;
		table->philos[i].last_eat = cur_time(0);
		table->philos[i].die_mutex = &table->die_mutex;
		table->philos[i].eat_mutex = &table->eat_mutex;
		// table->philos[i].full_eat = &table->eat_ptr;
		table->philos[i].time_to_eat = table->time_to_eat;
		table->philos[i].time_to_die = table->time_to_die;
		table->philos[i].time_to_sleep = table->time_to_sleep;
		table->philos[i].startime = table->startime;
		// table->philos[i].is_dead = &table->dead_ptr;
		table->philos[i].left = &table->forks[i];
		// printf ("%d philo left fork: %p\n", i + 1, table->philos[i].left);
		if (i == 0)
			table->philos[i].right = &table->forks[table->forks_count - 1];
		else
			table->philos[i].right = &table->forks[i - 1];
		// printf ("%d philo right fork: %p\n\n", i + 1, table->philos[i].right);
	}
}

int	initialization(t_deadly *table, int argc, char **argv)
{
	init_args(table, argc, argv);
	// table->eat_ptr = 0;
	table->startime = 0;
	// table->dead_ptr = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->forks_count);
	table->philos = malloc(sizeof(t_philo) * table->philo_count);
	if (err_msg(!table->forks || !table->philos, "Malloc error!") \
		|| init_mutexes(table))
		return (1);
	init_philos(table);
	return (0);
}
