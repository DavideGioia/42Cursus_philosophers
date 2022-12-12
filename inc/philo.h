/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:14:11 by dgioia            #+#    #+#             */
/*   Updated: 2022/12/12 19:00:37 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include	<sys/time.h>
# include	<stdlib.h>
# include	<pthread.h>
# include	<unistd.h>
# include	<stdio.h>
# include	<stdarg.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

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
	int             meals_nb;
	int             dead;
	int             finished;
	t_philo         *philos;
	long int		time_to_die;
	long int		time_to_sleep;
	long int		time_to_eat;
	long int		time_zero;
	pthread_mutex_t *forks;
	pthread_mutex_t lock;
	pthread_mutex_t write;
} t_data;

int	init(t_data *data, int argc, char **argv);
