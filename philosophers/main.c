/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:19:48 by jfrances          #+#    #+#             */
/*   Updated: 2023/07/13 10:31:12 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

static void	generate_philos(t_monitor *monitor)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * monitor->num_philos);
	if (!philo)
		error("Philosphers malloc error\n", monitor, philo, 1);
	initialize_philos(monitor, philo);
	generate_threads(monitor, philo);
}

static void	second_ignition(int ac, char **av)
{
	t_monitor	*monitor;
	int			i;

	i = -1;
	monitor = (t_monitor *)malloc(sizeof(t_monitor));
	if (!monitor)
		error("Monitor malloc error\n", monitor, 0, 1);
	monitor->num_philos = ft_atoi(av[0]);
	monitor->ttd = ft_atoi(av[1]);
	monitor->tte = ft_atoi(av[2]);
	monitor->tts = ft_atoi(av[3]);
	if (ac == 5)
		monitor->max_eat = ft_atoi(av[4]);
	else
		monitor->max_eat = -1;
	monitor->death = malloc(sizeof(pthread_mutex_t));
	if (!monitor->death)
		error("Mutex malloc error\n", monitor, 0, 1);
	monitor->forks = malloc(sizeof(pthread_mutex_t) * monitor->nbr_philo);
	if (!monitor->forks)
		error("Mutex fork malloc error\n", monitor, 0, 1);
	if (pthread_mutex_init(monitor->death, NULL) == -1)
		error("Mutex init failed\n", monitor, 0, 1);
	while (++i < monitor->num_philos)
	{
		if (pthread_mutex_init(&monitor->forks[i], NULL) == -1)
			error("Mutex init error\n", monitor, 0, 1);
	}
	generate_philos(&monitor);
}

static void	first_ignition(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (is_digit(av[i]) == -1)
		{
			ft_putstr_fd("Invalid Input\n", 2);
			return ;
		}
		i++;
	}
	second_ignition(ac, av);
}

int	main(int ac, char **av)
{
	if (!(ac >= 5 && ac <= 6))
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		return (0);
	}
	first_ignition(ac, av);
	return (0);
}
