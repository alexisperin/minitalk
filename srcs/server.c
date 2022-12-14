/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:41:56 by aperin            #+#    #+#             */
/*   Updated: 2022/12/06 15:45:11 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum)
{
	static char	buf[BUFFER_SIZE];
	static int	i = 0;
	static char	c = 0;
	static int	bits_received = 0;

	c += (signum == SIGUSR1);
	bits_received++;
	if (bits_received == CHAR_BIT)
	{
		buf[i] = c;
		i++;
		if (!c || i == BUFFER_SIZE)
		{
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
	pid_t	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
