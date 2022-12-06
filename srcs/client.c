/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:21:56 by aperin            #+#    #+#             */
/*   Updated: 2022/12/06 13:07:13 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	send_char(pid_t server_id, char c)
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
			return (0);
		}
		i++;
		usleep(50);
	}
	return (1);
}

int	main(int ac, char **av)
{
	pid_t	server_id;
	size_t	i;

	if (ac < 3)
		ft_printf("Not enough input arguments\n");
	else if (ac > 3)
		ft_printf("Too many input arguments\n");
	else
	{
		server_id = ft_atoi(av[1]);
		i = 0;
		while (av[2][i])
		{
			if (!send_char(server_id, av[2][i]))
				return (-1);
			i++;
		}
		if (!send_char(server_id, '\0'))
			return (-1);
		return (0);
	}
	return (-1);
}
