/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:36:31 by jfrances          #+#    #+#             */
/*   Updated: 2023/07/30 14:36:36 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->monitor->forks[philo->rfork]);
	writing("has taken a fork", philo, UNLOCK);
	pthread_mutex_lock(&philo->monitor->forks[philo->lfork]);
	writing("has taken a fork", philo, UNLOCK);
	pthread_mutex_lock(&philo->monitor->meal);
	writing("is eating", philo, UNLOCK);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->monitor->meal);
	sleeping(philo->monitor->to_eat, philo->monitor);
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->monitor->forks[philo->lfork]);
	pthread_mutex_unlock(&philo->monitor->forks[philo->rfork]);
}

void	sleeping(unsigned long length, t_env *monitor)
{
	unsigned long	time;

	time = get_time();
	while (!monitor->stop)
	{
		if (get_time() - time >= length)
			break ;
		usleep(monitor->count * 2);
	}
}

void	writing(char *to_write, t_philo *philo, int unlock)
{
	char	*str;

	str = ft_itoa(get_time() - philo->monitor->start);
	pthread_mutex_lock(&philo->monitor->write);
	if (!philo->monitor->stop && !philo->monitor->max_eat)
		printf("%s %s %s\n", str, philo->index_str, to_write);
	if (unlock)
		pthread_mutex_unlock(&philo->monitor->write);
	free(str);
}

void	is_dead(t_philo *philo, t_env *monitor)
{
	int	i;

	while (!monitor->max_eat)
	{
		i = -1;
		while (++i < monitor->count && !monitor->stop)
		{
			pthread_mutex_lock(&monitor->meal);
			if ((int)(get_time() - philo[i].last_meal) >= monitor->ttd)
			{
				writing("died", &philo[i], LOCK);
				monitor->stop = 1;
			}
			pthread_mutex_unlock(&monitor->meal);
		}
		if (monitor->stop)
			break ;
		i = 0;
		while (monitor->to_eat && i < monitor->count
			&& philo[i].times_eaten >= monitor->to_eat)
			i++;
		monitor->max_eat = (i == monitor->count);
	}
}

void	exit_threads(t_env *monitor)
{
	int	i;

	if (monitor->count == 1)
		pthread_detach(monitor->philos[0].id);
	else
	{
		i = -1;
		while (++i < monitor->count)
			pthread_join(monitor->philos[i].id, NULL);
	}
	i = -1;
	while (++i < monitor->count)
		pthread_mutex_destroy(&monitor->forks[i]);
	pthread_mutex_destroy(&monitor->meal);
	pthread_mutex_destroy(&monitor->write);
	i = -1;
	while (++i < monitor->count)
		free(monitor->philos[i].index_str);
	free(monitor->philos);
	free(monitor->forks);
}
