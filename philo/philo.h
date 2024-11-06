/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 22:36:52 by yyean-wa          #+#    #+#             */
/*   Updated: 2024/11/04 23:38:30 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				index;
	int				num;
	int				time_death;
	int				time_eat;
	int				time_sleep;
	int				check_full;
	int				must_eat;
	int				dead;
	long long		start_time;
	long long		*last_eat;
	pthread_mutex_t	eat_check;
	pthread_mutex_t	*fork;
}	t_philo;

int			ft_strlen(const char *str);
int			ft_atoi(const char *str);
void		ft_putnbr_fd(long long nbr, int fd);
void		ft_putendl_fd(char *str, int fd);
void		ft_putstr_fd(char *str, int fd);

long long	get_time(void);
void		args_error_msg(t_philo *philo);
void		dead_message(t_philo *philo, int id);
int			return_death(t_philo *philo);
void		message(long long time, int thread_id, \
	char *message, t_philo *philo);

void		timer(t_philo *philo, int action_time);

void		free_philo(t_philo *philo);

void		run_thread(t_philo *philo);
void		check_death(t_philo *philo);
void		swap_fork(int *first_fork, int *second_fork);

#endif
