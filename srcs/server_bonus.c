/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:31:56 by aperin            #+#    #+#             */
/*   Updated: 2022/12/07 11:35:19 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static char	buf[BUFFER_SIZE];
	static int	i = 0;
	static char	c = 0;
	static int	bits_received = 0;

	(void) context;
	c += (signum == SIGUSR1);
	bits_received++;
	if (bits_received == CHAR_BIT)
	{
		kill(info->si_pid, SIGUSR1);
		buf[i] = c;
		i++;
		if (!c || i == BUFFER_SIZE)
		{
			if (!c)
				kill(info->si_pid, SIGUSR2);
			write(1, buf, i);
			i = 0;
		}
		bits_received = 0;
		c = 0;
	}
	else
		c = c << 1;
}

int	main(void)
{
	struct sigaction	action;

	ft_printf("Server PID: %d\n", getpid());
	action.sa_sigaction = signal_handler;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	while (1)
		pause();
	return (0);
}
