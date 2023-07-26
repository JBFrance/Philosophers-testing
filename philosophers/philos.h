/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:31:19 by jfrances          #+#    #+#             */
/*   Updated: 2023/07/20 16:26:20 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H
# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philos
{
	int				index;
	int				status;
	int				time_from_meal;
	int				start;
	t_monitor		*seer;
	pthread_t		lclock;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}			t_philos;

typedef struct s_monitor
{
	int				num_philos;
	int				ttd;
	int				tte;
	int				tts;
	int				max_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*death;
}				t_monitor;

int		ft_atoi(const char *str);
int		is_digit(char *str);
void	ft_putstr_fd(char *s, int fd);
void	error(char *str, t_monitor *monitor, t_philo *philo, int malloc);
#endif
