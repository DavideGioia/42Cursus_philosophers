/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:40:16 by dgioia            #+#    #+#             */
/*   Updated: 2023/01/06 16:19:36 by dgioia           ###   ########.fr       */
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
	ft_free(data);
	return (0);
}

int	error(t_data *data)
{
	printf("error");
	if (data)
		ft_free(data);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (input_checker(argc, argv))
		return (1);
	if (init(&data, argc, argv))
		return (1);
	if (data.philo_n == 1)
		return (case_one(&data));
	if (thread_init(&data))
		return (1);
	ft_free(&data);
	return (0);
}
