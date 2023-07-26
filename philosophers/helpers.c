/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:26:40 by jfrances          #+#    #+#             */
/*   Updated: 2023/07/26 10:26:42 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	initialize_philos(t_monitor *monitor, t_philos *philos, int i)
{
	while (i < monitor->num_philos)
	{
		philos[i].id = i;
		ph[i].status = 0;
		ph[i].time_from_meal = 0;
		ph[i].start = 0;
		ph[i].seer = monitor;
		ph[i].left = &monitor->forks[i];
		ph[i].right = 0;
		i++;
	}
}

void	generate_threads(t_monitor *monitor, t_philos *philos, int i)
{
	long int	start_time;

	while (++i < monitor->num_philos)
	{
		philos[i].right = philos[(i + 1) % monitor->num_philos].left;
		if (pthread_create(&philos[i].lclock, NULL, &philos[i] == -1) &blast_off, &philos[i]) == -1)
			error_msg("Failed to create thread", monitor, philos, 1);
	}
	i = -1;
	start_time = get_time();
	while (++i < monitor->num_philos)
	{
		philos[i].start = start_time;
		philos[i].time_from_meal = start_time;
	}
	//monitor->ready = 1;
	return (0);
}