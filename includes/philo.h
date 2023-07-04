/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:30:20 by raghonya          #+#    #+#             */
/*   Updated: 2023/06/10 18:30:22 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# define DONTEAT 0
# define EAT 1

typedef struct s_philo
{
	int				id;
	struct timeval	time;
	pthread_t		philo;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	long long		last_eat;
	long long		startime;
	int				*is_dead;
	int				*full_eat;
	int				eat_count;
	pthread_mutex_t	*die_mutex;
	pthread_mutex_t	end_mutex;
	pthread_mutex_t	eat_mutex;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
}	t_philo;

typedef struct s_deadly
{
	struct timeval	time;
	pthread_mutex_t	*forks;
	int				eat_ptr;
	t_philo			*philos;
	int				dead_ptr;
	long long		startime;
	long long		showtime;
	pthread_mutex_t	end_mutex;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	eat_mutex;
	int				eat_limit;
	pthread_mutex_t	time_mutex;
	int				forks_count;
	int				philo_count;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;

}	t_deadly;

size_t		ft_strlen(char *s);
int			ft_isdigit(char c);
int			ft_atoi(const char *s);
int			parsing_args(char **argv);
long long	cur_time(long long start);
int			init_mutexes(t_deadly *table);
int			err_msg(int condition, char *msg);
int			gluttonous_philos(t_deadly *table);
int			check_philos_alive(t_deadly *table);
int			print_step(t_philo *philo, char *msg);
void		my_usleep(long long start, long long time_to);
int			clear_mutexes(t_deadly *table, int count);
int			initialization(t_deadly *table, int argc, char **argv);

#endif
