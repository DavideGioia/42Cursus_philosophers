/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:18:11 by dgioia            #+#    #+#             */
/*   Updated: 2022/12/23 22:45:20 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

long int	ft_atoi(char *str)
{
	int			x;
	long int	y;

	y = 0;
	x = 1;
	if ((*str == 43 || *str == 45) && ft_isdigit(*(str + 1)))
	{
		if (*str == 45)
			x *= -1;
		str++;
	}
	while (*str <= 57 && *str >= 48)
	{
		if (!ft_isdigit(*str) && *str != '\0')
			return (0);
		y = (y * 10) + ((*str - 48) % 10);
		str++;
	}
	if (!ft_isdigit(*str) && *str != '\0')
		return (0);
	y *= x;
	return (y);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_usleep(useconds_t time)
{
	u_int64_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return (0);
}
