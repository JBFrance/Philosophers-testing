/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:33:01 by jfrances          #+#    #+#             */
/*   Updated: 2023/07/29 15:32:50 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

static int	start_mutex(t_env *monitor, int i)
{
	while (++i < monitor->count)
	{
		if (pthread_mutex_init(&(monitor->forks[i]), NULL))
			return (0);
	}
	if (pthread_mutex_init(&monitor->meal, NULL))
		return (0);
	if (pthread_mutex_init(&monitor->write, NULL))
		return (0);
	return (1);
}

static int	start_philo(t_env *monitor, int i)
{	
	while (++i < monitor->count)
	{
		monitor->philos[i].times_eaten = 0;
		monitor->philos[i].index = i + 1;
		monitor->philos[i].index_str = ft_itoa(i + 1);
		if (!monitor->philos[i].index_str)
			break ;
		monitor->philos[i].lfork = i;
		monitor->philos[i].rfork = (i + 1) % monitor->count;
		monitor->philos[i].monitor = monitor;
	}
	if (i != monitor->count)
	{
		while (i >= 0)
		{
			free(monitor->philos[i].index_str);
			i--;
		}
		return (0);
	}
	return (1);
}

int	create_threads(t_env *monitor)
{
	monitor->philos = (t_philo *)malloc(sizeof(t_philo));
	if (!monitor->philos)
		return (0);
	monitor->forks = \
	(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * monitor->count);
	if (!monitor->forks)
	{
		free (monitor->philos);
		return (0);
	}
	if (!start_mutex(monitor, -1) || !start_philo(monitor, -1))
	{
		free(monitor->philos);
		free(monitor->forks);
		return (0);
	}
	return (1);
}
