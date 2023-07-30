/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:36:43 by jfrances          #+#    #+#             */
/*   Updated: 2023/07/30 14:36:46 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

static void	*routine2(void *args)
{
	int		i;
	t_philo	*philo;
	t_env	*monitor;

	i = 0;
	philo = (t_philo *)args;
	monitor = philo->monitor;
	if (philo->index % 2 && monitor->count > 1)
		sleeping(monitor->to_eat / 50, monitor);
	while (!monitor->stop && !monitor->max_eat)
	{
		eating(philo);
		writing("is sleeping", philo, UNLOCK);
		sleeping(monitor->tts, monitor);
		writing("is thinking", philo, UNLOCK);
	}
	return (NULL);
}

int	routine(t_env *monitor, int i)
{
	monitor->start = get_time();
	while (++i < monitor->count)
	{
		monitor->philos[i].last_meal = get_time();
		if (pthread_create(&monitor->philos[i].id, NULL, \
		routine2, &(monitor->philos[i])))
			return (0);
	}
	is_dead(monitor->philos, monitor);
	pthread_mutex_unlock(&monitor->write);
	exit_threads(monitor);
	return (1);
}
