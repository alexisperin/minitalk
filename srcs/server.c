/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:41:56 by aperin            #+#    #+#             */
/*   Updated: 2022/12/05 14:39:36 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "minitalk.h"
#include "ft_printf.h"

void	signal_handler(int signum)
{
	static char	c = 0;
	static int	bits_received = 0;

	c += (signum == SIGUSR2);
	bits_received++;
	if (bits_received == CHAR_BIT)
	{
		write(1, &c, 1);
		bits_received = 0;
		c = 0;
	}
	c = c << 1;
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
