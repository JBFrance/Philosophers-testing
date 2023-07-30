/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:35:45 by jfrances          #+#    #+#             */
/*   Updated: 2023/07/28 14:35:46 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	main(int argc, char **argv)
{
	t_env	monitor;

	monitor.max_eat = 0;
	monitor.stop = 0;
	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd(("Invalid Number of Arguments\n"), 2);
		return (0);
	}
	if (!params(&monitor, argc, argv))
		return (ft_putstr_fd("Error: Invalid input, Integers Only\n", 2), 0);
	if (!create_threads(&monitor))
		return (ft_putstr_fd("Error: Values Could Not Be Intialized\n", 2), 0);
	if (!routine(&monitor, -1))
		return (ft_putstr_fd("Error: Threads Could Not Be Started\n", 2), 0);
}
