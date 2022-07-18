/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:25:53 by taehooki          #+#    #+#             */
/*   Updated: 2022/07/17 23:31:23 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_data	g_data;

void	handshake_synack(int signo, siginfo_t *info, void *context)
{
	if (info->si_pid <= 100)
		return ;
	(void)context;
	g_data.pid = info->si_pid;
	ft_kill(g_data.pid, signo + 1);
	sigaction(SIGUSR1, &g_data.action_transmission, NULL);
	sigaction(SIGUSR2, &g_data.action_transmission, NULL);
}

static void	init(void)
{
	g_data.action_handshake.sa_flags = SA_SIGINFO | SA_NODEFER;
	g_data.action_transmission.sa_flags = SA_SIGINFO | SA_NODEFER;
	g_data.action_handshake.sa_sigaction = handshake_synack;
	g_data.action_transmission.sa_sigaction = ft_receive_signal;
	sigemptyset(&g_data.action_handshake.sa_mask);
	sigemptyset(&g_data.action_transmission.sa_mask);
	g_data.pid = 0;
	g_data.byte = 0;
	g_data.message = (char *)malloc(sizeof(char) * 100);
	if (!g_data.message)
		ft_error("Memory allocation Error");
	ft_bzero(g_data.message, 100);
	sigaction(SIGUSR1, &g_data.action_handshake, NULL);
	sigaction(SIGUSR2, &g_data.action_handshake, NULL);
	ft_putstr_fd("Server PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
		ft_error("Arguments Error : ./server");
	init();
	while (1)
		pause();
	return (0);
}
