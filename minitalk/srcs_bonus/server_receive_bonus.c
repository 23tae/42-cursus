/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_receive_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:28:13 by taehooki          #+#    #+#             */
/*   Updated: 2022/07/18 22:57:34 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	print_message(int index)
{
	write(1, g_data.message, index + 1);
	ft_bzero(g_data.message, index + 1);
	return (-1);
}

static int	signal_to_char(int signo)
{
	static int	bit = 7;
	static int	index;
	int			is_end;

	is_end = 0;
	if (!bit && !g_data.byte)
		ft_putendl_fd("-------------Message-------------", 1);
	if (signo == SIGUSR1)
		g_data.message[index] += (1 << bit);
	if (!bit && (g_data.message[index] == '\0'))
	{
		index = print_message(index);
		is_end = 1;
	}
	else if (!bit && (index == 99))
		index = print_message(index);
	--bit;
	if (bit == -1)
	{
		bit = 7;
		++index;
		++g_data.byte;
	}
	return (is_end);
}

void	ft_receive_signal(int signo, siginfo_t *info, void *context)
{
	int	is_end;

	(void)context;
	if (info->si_pid != g_data.pid)
	{
		if (info->si_pid > 100)
			ft_kill(info->si_pid, signo);
		return ;
	}
	is_end = signal_to_char(signo);
	if (is_end)
	{
		ft_putstr_fd("\n-------------Details-------------\n", 1);
		ft_putstr_fd("Sender PID : ", 1);
		ft_putnbr_fd(g_data.pid, 1);
		ft_putstr_fd("\nReceived bytes : ", 1);
		ft_putnbr_fd(g_data.byte, 1);
		ft_putstr_color_fd(COLOR_BLUE, "\nReceiving : Success\n", 1);
		sigaction(SIGUSR1, &g_data.action_handshake, NULL);
		sigaction(SIGUSR2, &g_data.action_handshake, NULL);
		g_data.byte = 0;
	}
	ft_kill(g_data.pid, SIGUSR1 + is_end);
}
