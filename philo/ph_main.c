/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:22:23 by yyean-wa          #+#    #+#             */
/*   Updated: 2024/11/05 18:48:51 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_thread(t_philo *philo)
{
	int	a;

	philo->fork = malloc(sizeof(pthread_mutex_t) * philo->num);
	a = -1;
	while (++a < philo->num)
		pthread_mutex_init(&(philo->fork[a]), NULL);
	pthread_mutex_init(&(philo->eat_check), NULL);
}

void	init_philo(t_philo *philo, int argc, char **argv)
{
	philo->num = ft_atoi(argv[1]);
	philo->time_death = ft_atoi(argv[2]);
	philo->time_eat = ft_atoi(argv[3]);
	philo->time_sleep = ft_atoi(argv[4]);
	philo->start_time = get_time();
	philo->dead = 0;
	philo->must_eat = ft_atoi(argv[5]);
	if (argc == 6)
		philo->check_full = 0;
	else
		philo->check_full = -1;
	if (philo->num < 1 || philo->time_death < 60 || philo->time_eat < 60 || \
		philo->time_sleep < 60 || philo->must_eat < -1)
	{
		ft_putendl_fd("Error: Invalid input", 2);
		args_error_msg(philo);
		exit (1);
	}
	philo->last_eat = malloc(sizeof(long long) * philo->num);
	init_thread(philo);
	return ;
}

void	*one_philo(void *alone)
{
	t_philo	*philo;

	philo = (t_philo *)alone;
	message(get_time(), 1, "has taken a fork", philo);
	timer(philo, philo->time_death + 1);
	message(get_time(), 1, "died", philo);
	return (NULL);
}

void	free_philo(t_philo *philo)
{
	int	a;

	a = -1;
	while (++a < philo->num)
		pthread_mutex_destroy(&(philo->fork[a]));
	free(philo->fork);
	free(philo->last_eat);
	pthread_mutex_destroy(&philo->eat_check);
}

int	main(int argc, char **argv)
{
	t_philo		philo;
	pthread_t	thread;

	if (argc != 5 && argc != 6)
	{
		ft_putendl_fd("Error: Invalid number of arguments", 2);
		ft_putstr_fd("Expected input: [num_of_philo] [time_to_die] ", 2);
		ft_putendl_fd("[time_to_eat] [time_to_sleep]", 2);
		ft_putendl_fd("(Optional->[num_of_times_each_philo_must_eat])", 2);
		return (1);
	}
	init_philo(&philo, argc, argv);
	if (philo.num == 1)
	{
		pthread_create(&thread, NULL, &one_philo, (void *)&philo);
		pthread_join(thread, NULL);
	}
	else
		run_thread(&philo);
	free_philo(&philo);
	return (0);
}
