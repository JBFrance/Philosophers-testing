/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 07:27:54 by jfrances          #+#    #+#             */
/*   Updated: 2023/07/26 07:27:56 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	error(char *str, t_monitor *monitor, t_philo *philo, int malloc)
{
	if (malloc)
	{
		if (monitor->death)
			free(monitor->death);
		if (monitor->forks)
			free(monitor->forks);
		if (philo)
			free(philo);
	}
	ft_putstr_fd(str, 2);
	exit(1);
}

void	free_thread(t_monitor *monitor, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < monitor->num_philos)
	{
		pthread_join(philo[i].ttd, (void *)&ph[i]);
		i++;
	}
	pthread_mutex_destroy(monitor->death);
	pthread_mutex_destroy(monitor->forks);
	free(monitor->death);
	free(monitor->forks);
	free(ph);
}
