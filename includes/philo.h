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

typedef struct s_human
{
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
	pthread_t		philo;
	int				id;
}	t_philo;

typedef struct s_philo
{
	pthread_mutex_t	*forks;
	t_philo			*philos;
	int				die_state;
	int				eat_limit;
	int				forks_count;
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;

}	t_deadly;


size_t	ft_strlen(char *s);
int		ft_isdigit(char c);
int		ft_atoi(const char *s);
int		parsing_args(char **argv);
int		err_msg(int condition, char *msg);
int		gluttonous_philos(t_deadly *philo);
int		initialization(t_deadly *philo, int argc, char **argv);

#endif
