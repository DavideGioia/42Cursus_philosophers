/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:02:13 by dgioia            #+#    #+#             */
/*   Updated: 2023/01/04 06:53:48 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	init_alloc(t_data *data)
{
	data->tid = malloc(sizeof(pthread_t) * data->philo_n);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_n);
	data->philos = malloc(sizeof(t_philo) * data->philo_n);
	if (!data->tid || !data->forks || !data->philo_n)
		return (1);
	return (0);
}

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_n)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	data->philos[0].l_fork = &data->forks[0];
	data->philos[0].r_fork = &data->forks[data->philo_n - 1];
	i = 1;
	while (i < data->philo_n)
	{
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].r_fork = &data->forks[i - 1];
		i++;
	}
	return (0);
}

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_n)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].time_to_die = data->time_to_die;
		data->philos[i].eat_cont = 0;
		data->philos[i].eating = 0;
		data->philos[i].status = 0;
		pthread_mutex_init(&data->philos[i].lock, NULL);
		i++;
	}
}

int	init_data(t_data *data, int argc, char **argv)
{
	data->philo_n = (int) ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->cycles = (int) ft_atoi(argv[5]);
	else
		data->cycles = -1;
	data->dead = 0;
	data->finished = 0;
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
}

int	init(t_data *data, int argc, char **argv)
{
	if (init_data(data, argc, argv))
		return (1);
	if (init_alloc(data))
		return (1);
	if (init_forks(data))
		return (1);
	init_philos(data);
	return (0);
}
