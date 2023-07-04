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
	pthread_mutex_t	end_mutex;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	eat_mutex;
	int				eat_limit;
	int				forks_count;
	int				philo_count;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;

}	t_deadly;

size_t		ft_strlen(char *s);
int			ft_isdigit(char c);
int			ft_atoi(const char *s);
int			is_dead(t_philo *philo);
int			parsing_args(char **argv);
long long	cur_time(long long start);
int			die_check(t_deadly *table);
int			full_check(t_deadly *table);
void		wait_threads(t_deadly *table);
int			init_mutexes(t_deadly *table);
int			err_msg(int condition, char *msg);
int			gluttonous_philos(t_deadly *table);
int			check_philos_alive(t_deadly *table);
void		print_step(t_philo *philo, char *msg);
int			clear_mutexes(t_deadly *table, int count);
int			initialization(t_deadly *table, int argc, char **argv);
void		my_usleep(t_philo *philo, long long start, long long time_to);

#endif
