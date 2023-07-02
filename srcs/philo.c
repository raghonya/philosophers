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

void	wait_threads(t_deadly table)
{
	int	i;

	i = -1;
	while (++i < table.philo_count)
		pthread_join(table.philos[i].philo, NULL);
}

long long	cur_time(long long start)
{
	struct timeval	time;
	long long		time_ms;
	gettimeofday(&time, NULL);
	time_ms =  (time.tv_sec) * 1000 \
		+ (time.tv_usec) / 1000;
	return (time_ms - start);
}

int	main(int argc, char **argv)
{
	t_deadly	table;

	if (err_msg (argc != 5 && argc != 6, "Give at least 5 arguments") \
		|| parsing_args(argv) || initialization(&table, argc, argv) \
		|| gluttonous_philos(&table))
		return (1);
	while (1)
		if (check_philos_alive(&table))
		{
			// printf ("asdn\nsfsafasfsa\nsadasfasf\\n\nn\n\n\\n\n\n\n\n\nn\ndbdsbfds\nasdasdasdsada\n");
			return (0);
		}
}
