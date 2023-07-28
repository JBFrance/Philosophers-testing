/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:48:40 by jfrances          #+#    #+#             */
/*   Updated: 2023/07/28 14:48:42 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

static int	is_digit(char *str)
{
	int		i;
	int		neg;
	long	value;

	i = 0;
	value = 0;
	neg = 0;
	while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		if (val > MXINT1 || (val == MXINT1 && \
		((!neg && str[i] - '0' > 7) || (neg && str[i] - '0' > 8))))
			return (0);
		else
			value = (value * 10) + str[i++] - '0';
	}
	return (1);

}

static int	ft_atoi(char *str)
{
	int	result;
	int	is_neg;

	result = 0;
	is_neg = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		is_neg *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	result *= is_neg;
	return (result);
}

int	params(t_env *monitor, int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (!is_digit(argv[i]) || ft_atoi(argv[i]) < 0)
			return (0);
	}
	monitor->count = ft_atoi(argv[1]);
	monitor->ttd = ft_atoi(argv[2]);
	monitor->tte = ft_atoi(argv[3]);
	monitor->tts = ft_atoi(argv[4]);
	if (argc == 6)
		monitor->to_eat = ft_atoi(argv[5]);
	else
		monitor->to_eat = 0;
	if (monitor->count < 1)
		return (0);
	return (1);
}

