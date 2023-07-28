/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:15:51 by jfrances          #+#    #+#             */
/*   Updated: 2023/07/28 14:34:58 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILOS_H
# define PHILOS_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unsitd.h>
# include <sys/time.h>

# define UNLOCK 1
# define LOCK 0
# define MAXINT1 214748364

struct	s_env;

typedef struct s_philo
{
	int				times_eaten;
	int				index;
	char			*index_str;
	int				lfork;
	int				rfork;
	unsigned long	last_meal;
	struct s_env	*monitor;
	pthread_t		id;
}				t_philo;

typedef struct	s_env
{
	int	count;
	int	ttd;
	int	tte;
	int	tts;
	int	to_eat;
	int	stop;
	int	max_eat;
	unsigned long	start;
	t_philo	*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	meal;
	pthread_mutex_t	write;
}			t_env;

int	params(t_env *monitor, int argc, char **argv);

#endif
