/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:41:56 by aperin            #+#    #+#             */
/*   Updated: 2022/12/05 13:32:43 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "minitalk.h"
#include "ft_printf.h"

void	binary_to_char(int binary[CHAR_BIT])
{
	char	c;
	int		i;

	c = 0;
	i = 0;
	while (i < CHAR_BIT)
	{
		c *= 2;
		c += binary[i];
		i++;
	}
	write(1, &c, 1);
}

void	signal_handler(int signum)
{
	static int	binary[CHAR_BIT];
	static int	i;

	if (signum == SIGUSR1)
		binary[i] = 0;
	else
		binary[i] = 1;
	if (i < CHAR_BIT - 1)
		i++;
	else
	{
		i = 0;
		binary_to_char(binary);
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		pause();
	}
}
