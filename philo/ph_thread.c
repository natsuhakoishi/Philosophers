/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 00:01:02 by yyean-wa          #+#    #+#             */
/*   Updated: 2024/11/04 00:50:50 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo, int thread_id, int *num_eat)
{
	int	first_fork;
	int	second_fork;

	first_fork = thread_id;
	second_fork = (thread_id + 1) % philo->num;
	if (first_fork > second_fork)
		swap_fork(&first_fork, &second_fork);
	pthread_mutex_lock(&(philo->fork[first_fork]));
	message(get_time(), thread_id + 1, "has taken a fork", philo);
	pthread_mutex_lock(&(philo->fork[second_fork]));
	message(get_time(), thread_id + 1, "has taken a fork", philo);
	message(get_time(), thread_id + 1, "is eating", philo);
	pthread_mutex_lock(&philo->eat_check);
	philo->last_eat[thread_id] = get_time();
	*num_eat += 1;
	if (philo->check_full >= 0 && *num_eat == philo->must_eat)
		++philo->check_full;
	pthread_mutex_unlock(&philo->eat_check);
	timer(philo, philo->time_eat);
	pthread_mutex_unlock(&(philo->fork[first_fork]));
	pthread_mutex_unlock(&(philo->fork[second_fork]));
}

void	sleep_think(t_philo *philo, int thread_id)
{
	message(get_time(), thread_id + 1, "is sleeping", philo);
	timer(philo, philo->time_sleep);
	message(get_time(), thread_id + 1, "is thinking", philo);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		thread_id;
	int		num_eat;

	philo = (t_philo *)arg;
	thread_id = philo->index;
	num_eat = 0;
	while (!return_death(philo))
	{
		if (!return_death(philo))
			eat(philo, thread_id, &num_eat);
		if (!return_death(philo))
			sleep_think(philo, thread_id);
	}
	return (NULL);
}

void	check_death(t_philo *philo)
{
	int	a;
	int	ofl;

	ofl = 1;
	while (ofl)
	{
		a = -1;
		while (ofl && ++a < philo->num)
		{
			pthread_mutex_lock(&philo->eat_check);
			if (get_time() - philo->last_eat[a] > philo->time_death)
			{
				ofl = 0;
				philo->dead = 1;
				dead_message(philo, a + 1);
			}
			else if (philo->check_full == philo->num)
			{
				ofl = 0;
				philo->dead = 1;
			}
			pthread_mutex_unlock(&philo->eat_check);
		}
	}
}

void	run_thread(t_philo *philo)
{
	pthread_t	*thread;
	int			a;

	thread = malloc(sizeof(pthread_t) * philo->num);
	a = -1;
	while (++a < philo->num)
	{
		pthread_mutex_lock(&philo->eat_check);
		philo->index = a;
		philo->last_eat[a] = philo->start_time;
		pthread_mutex_unlock(&philo->eat_check);
		pthread_create(&(thread[a]), NULL, &routine, (void *)philo);
		usleep(100);
	}
	check_death(philo);
	a = -1;
	while (++a < philo->num)
		pthread_join(thread[a], NULL);
	free(thread);
}
