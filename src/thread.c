/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:23:07 by dgioia            #+#    #+#             */
/*   Updated: 2023/01/04 06:57:47 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long int	get_time(void)
{
	struct timeval	tv;
	
	if (gettimeofday(&tv, NULL))
		return (1);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	*monitor(void *data_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) data_pointer;
	pthread_mutex_lock(&philo->data->write);
	printf("data val: %d", philo->data->dead);
	pthread_mutex_unlock(&philo->data->write);
	while (philo->data->dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->data->finished >= philo->data->philo_n)
			philo->data->dead = 1;
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

void	*supervisor(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *) philo_ptr;
	while (philo->data->dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (get_time() >= philo->time_to_die && philo->eating == 0)
			message(DIED, philo);
		if (philo->eat_cont == philo->data->cycles)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->finished++;
			philo->eat_cont++;
			pthread_mutex_unlock(&philo->data->lock);
		}
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}

void	*routine(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) philo_pointer;
	philo->time_to_die = philo->data->time_to_die + get_time();
	if (pthread_create(&philo->t1, NULL, &supervisor, (void *)philo))
		return ((void *)1);
	while (philo->data->dead == 0)
	{
		eat(philo);
		message(THINKING, philo);
	}
	if (pthread_join(philo->t1, NULL))
		return ((void *)1);
	return ((void *)0);
}

int	thread_init(t_data *data)
{
	int			i;
	pthread_t	t0;

	i = -1;
	data->start_time = get_time();
	if (data->cycles > 0)
	{
		if (pthread_create(&t0, NULL, &monitor, &data->philos[0]))
			return (1);
	}
	while (++i < data->philo_n)
	{
		if (pthread_create(&data->tid[i], NULL, &routine, &data->philos[i]))
			return (1);
		ft_usleep(1);
	}
	i = -1;
	while (++i < data->philo_n)
	{
		if (pthread_join(data->tid[i], NULL))
			return (1);
	}
	return (0);
}