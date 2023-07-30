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
# include <unistd.h>
# include <sys/time.h>

# define UNLOCK 1
# define LOCK 0
# define MXINT1 214748364

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

int				create_threads(t_env *monitor);
int				params(t_env *monitor, int argc, char **argv);
void			eating(t_philo *philo);
void			sleeping(unsigned long length, t_env *monitor);
void			writing(char *to_write, t_philo *philo, int unlock);
void			is_dead(t_philo *phil, t_env *monitor);
int				routine(t_env *monitor, int i);
int				ft_strlen(const char *str);
void			ft_putstr_fd(char *str, int fd);
char			*ft_itoa(int n);
char			*ft_strdup(const char *s1);
unsigned long	get_time(void);
void			exit_threads(t_env *monitor);
#endif
