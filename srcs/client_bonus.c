/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:31:50 by aperin            #+#    #+#             */
/*   Updated: 2022/12/07 11:16:33 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int signum)
{
	static int	ack = 0;

	if (signum == SIGUSR1)
		ack++;
	else
		ft_printf("Received: %d\n", ++ack);
}

static void	send_char(pid_t server_id, char c)
{
	int	i;
	int	ret;

	i = 0;
	while (i < CHAR_BIT)
	{
		if ((c >> (CHAR_BIT - 1 - i)) & 1)
			ret = kill(server_id, SIGUSR1);
		else
			ret = kill(server_id, SIGUSR2);
		if (ret == -1)
		{
			ft_printf("Message could not be sent\n");
			exit(EXIT_FAILURE);
		}
		i++;
		usleep(50);
	}
}

static void	send_string(pid_t server_id, char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		send_char(server_id, str[i]);
		i++;
	}
	send_char(server_id, '\0');
	ft_printf("Sent: %d\n", ++i);
}

int	main(int ac, char **av)
{
	pid_t	server_id;

	if (ac == 3)
	{
		server_id = ft_atoi(av[1]);
		send_string(server_id, av[2]);
		return (0);
	}
	else if (ac < 3)
		ft_printf("Not enough input arguments\n");
	else
		ft_printf("Too many input arguments\n");
	return (-1);
}
