/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 22:47:46 by yyean-wa          #+#    #+#             */
/*   Updated: 2024/11/04 18:07:46 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(const char *str)
{
	int	a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

int	ft_atoi(const char *str)
{
	long	res;
	int		i;

	if (!str)
		return (-1);
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		return (-2);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
		if (res > INT_MAX)
			return (-2);
	}
	if (str[i] && (str[i] < '0' || str[i] > '9'))
		return (-2);
	return ((int)(res));
}

void	ft_putnbr_fd(long long nbr, int fd)
{
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	else
	{
		nbr += '0';
		write(fd, &nbr, 1);
	}
}

void	ft_putendl_fd(char *str, int fd)
{
	int	a;

	if (!str)
		return ;
	a = 0;
	while (str[a])
		write(fd, &str[a++], 1);
	write(fd, "\n", 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	a;

	if (!str)
		return ;
	a = 0;
	while (str[a])
		write(fd, &str[a++], 1);
}
