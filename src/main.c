/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:40:16 by dgioia            #+#    #+#             */
/*   Updated: 2022/12/13 19:37:16 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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
	// pthread_mutex_t	mutex;
	// pthread_t	tid;
	
	if (input_checker(argc, argv))
		return (1);
	if (init(&data, argc, argv))
		return (1);
	//pthread_mutex_init(&mutex, NULL);

	//pthread_create(&tid, NULL, &routine, &data_pointer);
	return (0);
}
