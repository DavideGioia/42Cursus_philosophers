/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:12:48 by dgioia            #+#    #+#             */
/*   Updated: 2022/12/23 22:47:36 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	message(char *str, t_philo *philo)
{
	long long unsigned int	time;
	
	pthread_mutex_lock(&philo->data->write);
	time = get_time() - philo->data->start_time;
	if(ft_strcmp(DIED, str) == 0 && philo->data->dead == 0)
	{
		printf("%llu %d %s\n", time, philo->id, str);
		philo->data->dead = 1;
	}
	if (!philo->data->dead)
		printf("%llu %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->write);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	message(TAKE_FORKS, philo);
	pthread_mutex_lock(philo->l_fork);
	message(TAKE_FORKS, philo);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	message(SLEEPING, philo);
	ft_usleep(philo->data->time_to_sleep);
}

void	eat(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->lock);
	philo->eating = 1;
	philo->time_to_die = get_time() + philo->data->time_to_die;
	message(EATING, philo);
	philo->eat_cont++;
	ft_usleep(philo->data->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->lock);
	drop_forks(philo);
}