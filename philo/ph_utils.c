/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 23:10:28 by yyean-wa          #+#    #+#             */
/*   Updated: 2024/11/03 01:12:10 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	args_error_msg(t_philo *philo)
{
	if (philo->num < 1)
		ft_putendl_fd("Invalid numbers of philosopher(s) (minimum 1)", 2);
	if (philo->time_death < 60)
		ft_putendl_fd("Invalid time_to_die (minimum 60)", 2);
	if (philo->time_eat < 60)
		ft_putendl_fd("Invalid time_to_eat (minimum 60)", 2);
	if (philo->time_sleep < 60)
		ft_putendl_fd("Invalid time_to_sleep (minimum 60)", 2);
	if (philo->must_eat < -1)
		ft_putendl_fd("Invalid num_of_times_philo_must_eat (minimum 0)", 2);
}

void	dead_message(t_philo *philo, int id)
{
	ft_putnbr_fd((get_time() - philo->start_time), 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(id, 1);
	ft_putstr_fd(" ", 1);
	ft_putendl_fd("died", 1);
}

int	return_death(t_philo *philo)
{
	int	f;

	f = 0;
	pthread_mutex_lock(&philo->eat_check);
	if (philo->dead)
		f = 1;
	pthread_mutex_unlock(&philo->eat_check);
	return (f);
}

void	message(long long time, int thread_id, char *message, t_philo *philo)
{
	if (return_death(philo))
		return ;
	pthread_mutex_lock(&philo->eat_check);
	ft_putnbr_fd((time - philo->start_time), 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(thread_id, 1);
	ft_putstr_fd(" ", 1);
	ft_putendl_fd(message, 1);
	pthread_mutex_unlock(&philo->eat_check);
}
