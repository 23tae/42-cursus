/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:25:20 by taehooki          #+#    #+#             */
/*   Updated: 2022/07/17 23:31:15 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_data	g_data;

void	handshake_syn(void)
{
	static int	request_count;

	if (request_count == 10)
		ft_error("Connection : Failure");
	ft_kill(g_data.pid, SIGUSR1);
	request_count++;
}

static void	handshake_ack(int signo, siginfo_t *info, void *context)
{
	(void)context;
	if ((info->si_pid == g_data.pid) && (signo == SIGUSR2))
	{
		ft_putendl_fd("Connection : Success", 1);
		sigaction(SIGUSR1, &g_data.action_transmission, NULL);
		sigaction(SIGUSR2, &g_data.action_transmission, NULL);
		usleep(10);
		ft_send_message();
	}
	else
	{
		sleep(1);
		handshake_syn();
	}
}

static void	init(char **argv)
{
	g_data.action_handshake.sa_flags = SA_SIGINFO | SA_NODEFER;
	g_data.action_transmission.sa_flags = SA_SIGINFO | SA_NODEFER;
	g_data.action_handshake.sa_sigaction = handshake_ack;
	g_data.action_transmission.sa_sigaction = ft_send_or_end;
	sigemptyset(&g_data.action_handshake.sa_mask);
	sigemptyset(&g_data.action_transmission.sa_mask);
	g_data.message = argv[2];
	g_data.byte = 0;
	sigaction(SIGUSR1, &g_data.action_handshake, NULL);
	sigaction(SIGUSR2, &g_data.action_handshake, NULL);
	ft_putstr_fd("-------------Details-------------\n", 1);
	ft_putstr_fd("Client PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
}

static int	check_argument(int argc, char **argv)
{
	if (argc != 3)
		return (-1);
	g_data.pid = ft_atoi(argv[1]);
	if (g_data.pid <= 0)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (check_argument(argc, argv))
		ft_error("Arguments Error : ./client [PID] [Message]");
	init(argv);
	handshake_syn();
	while (1)
		pause();
	return (0);
}
