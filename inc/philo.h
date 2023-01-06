/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:14:11 by dgioia            #+#    #+#             */
/*   Updated: 2023/01/06 16:20:47 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define TAKE_FORKS "has taken a fork"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define DIED "died"

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t       t1;
	int             id;
	int             eat_cont;
	int             status;
	int             eating;
	long int		time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
} t_philo;

typedef struct s_data
{
	pthread_t       *tid;
	int             philo_n;
	int             cycles;
	int             dead;
	int             finished;
	t_philo         *philos;
	long int		time_to_die;
	long int		time_to_sleep;
	long int		time_to_eat;
	long int		start_time;
	pthread_mutex_t *forks;
	pthread_mutex_t lock;
	pthread_mutex_t write;
} t_data;

int	init(t_data *data, int argc, char **argv);

long int	ft_atoi(char *str);
int			ft_strcmp(const char *s1, const char *s2);
int	ft_usleep(useconds_t time);
void	eat(t_philo *philo);
int	thread_init(t_data *data);

long int	get_time(void);

void	message(char *str, t_philo *philo);

void	*routine(void *philo_ptr);
void	ft_free (t_data *data);
int	error(t_data *data);
int	input_checker(int argc, char **argv);
#endif