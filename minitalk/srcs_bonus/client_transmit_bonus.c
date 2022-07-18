/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_transmit_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:27:59 by taehooki          #+#    #+#             */
/*   Updated: 2022/07/17 12:28:06 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	send_signal(char c, int bit)
{
	if ((c >> bit) & 1)
		ft_kill(g_data.pid, SIGUSR1);
	else
		ft_kill(g_data.pid, SIGUSR2);
}

void	ft_send_message(void)
{
	static int	bit = 7;
	static int	index;

	send_signal(g_data.message[index], bit);
	--bit;
	if (bit == -1)
	{
		bit = 7;
		++index;
		++g_data.byte;
	}
}

void	ft_send_or_end(int signo, siginfo_t *info, void *context)
{
	(void)context;
	if (info->si_pid != g_data.pid)
		return ;
	if (signo == SIGUSR1)
		ft_send_message();
	else if (signo == SIGUSR2)
	{
		ft_putstr_fd("Transmitted bytes : ", 1);
		ft_putnbr_fd(g_data.byte, 1);
		ft_putstr_color_fd(COLOR_BLUE, "\nTransmission : Success\n", 1);
		exit(0);
	}
}
