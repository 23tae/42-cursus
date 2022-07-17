/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:03:38 by taehooki          #+#    #+#             */
/*   Updated: 2022/07/17 09:41:31 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_kill(pid_t pid, int signo)
{
	if (kill(pid, signo))
		ft_error("\nSignal sending : Failure.");
}

void	ft_error(char *str)
{
	ft_putstr_color_fd(COLOR_RED, str, 1);
	write(1, "\n", 1);
	exit(1);
}
