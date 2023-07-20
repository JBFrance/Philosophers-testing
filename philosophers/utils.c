#include "philos.h"

int	ft_atoi(const char *str)
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

int	is_digit(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (str[i])
	{
		printf("str = [%c], i = [%d], flag = [%d]\n", str[i], i, flag);
		if (!(str[i] >= '0' && str[i] <= '9'))
			flag = 1;
		if (flag == 1 && str[i] == '+')
			flag = 0;
		i++;
	}
	if (flag == 1)
		return (-1);
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write (fd, s, i);
}
