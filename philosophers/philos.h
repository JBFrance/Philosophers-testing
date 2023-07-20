/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:31:19 by jfrances          #+#    #+#             */
/*   Updated: 2023/07/13 19:22:47 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H
# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philo
{
	int	ttd;
	int	tte;
	int	tts;
	int	max_eat;
	int	l_fork;
	int	r_fork;
}			t_philo;

typedef struct s_monitor
{
	int			num_philos;
	int			ttd;
	int			tte;
	int			tts;
	int			max_eat;
	pthread_t	*arr;
}				t_monitor;

int		ft_atoi(const char *str);
int		is_digit(char *str);
void	ft_putstr_fd(char *s, int fd);
#endif
