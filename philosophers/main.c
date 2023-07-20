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

static void	second_ignition(int ac, char **av)
{
	t_monitor	monitor;

	monitor.num_philos = ft_atoi(av[0]);
	monitor.ttd = ft_atoi(av[1]);
	monitor.tte = ft_atoi(av[2]);
	monitor.tts = ft_atoi(av[3]);
	if (ac == 5)
		monitor.max_eat = ft_atoi(av[4]);
	else
		monitor.max_eat = -1;
	monitor.arr = NULL;
	//blast_off(&monitor);
}

static void	first_ignition(int ac, char **av)
{
	int	i;

	i = 0;
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
