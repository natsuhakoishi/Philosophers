/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 23:57:18 by yyean-wa          #+#    #+#             */
/*   Updated: 2024/11/04 00:43:54 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	timer(t_philo *philo, int action_time)
{
	long long	start;

	start = get_time();
	while (!return_death(philo))
	{
		if (get_time() - start >= action_time)
			return ;
		usleep(40);
	}
}

void	swap_fork(int *first_fork, int *second_fork)
{
	int	temp;

	temp = *first_fork;
	*first_fork = *second_fork;
	*second_fork = temp;
}
