/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:02:23 by taehooki          #+#    #+#             */
/*   Updated: 2022/07/17 23:30:59 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <sys/types.h>
# include "../libft/libft.h"

typedef struct s_data
{
	struct sigaction	action_handshake;
	struct sigaction	action_transmission;
	pid_t				pid;
	char				*message;
	int					byte;
}	t_data;

extern t_data	g_data;

//server
void	ft_receive_signal(int signo, siginfo_t *info, void *context);

//client
void	ft_send_or_end(int signo, siginfo_t *info, void *context);
void	ft_send_message(void);

//utils
void	ft_kill(pid_t pid, int signo);
void	ft_error(char *str);

#endif