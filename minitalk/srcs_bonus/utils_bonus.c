/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:29:22 by taehooki          #+#    #+#             */
/*   Updated: 2022/07/18 22:48:33 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_kill(pid_t pid, int signo)
{
	usleep(10);
	if (kill(pid, signo))
		ft_error("\nConnection : Failure.");
}

void	ft_error(char *str)
{
	ft_putstr_color_fd(COLOR_RED, str, 1);
	write(1, "\n", 1);
	exit(1);
}
