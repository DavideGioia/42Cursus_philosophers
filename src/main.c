/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:40:16 by dgioia            #+#    #+#             */
/*   Updated: 2023/01/04 07:06:21 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	case_one(t_data *data)
{
	data->start_time = get_time();
	if (pthread_create(&data->tid[0], NULL, &routine, &data->philos[0]))
		return (1);
	pthread_detach(data->tid[0]);
	while (data->dead == 0)
		ft_usleep(0);
	//ft_exit(data);
	return (0);
}

int	input_checker(int argc, char **argv)
{
	int	i;
	int j;

	if (argc < 5 || argc > 6)
		return (1);
	if (ft_atoi(argv[1]) > 200)
		return (1);
	i = 1;
	while(argv[i])
	{
		if (ft_atoi(argv[i]) <= 0)
			return (1);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_data	data;
	
	if (input_checker(argc, argv))
		return (1);
	if (init(&data, argc, argv))
		return (1);
	if (data.philo_n == 1)
		return (case_one(&data));
	if (thread_init(&data))
		return(1);
	ft_free(&data);
	return (0);
}
