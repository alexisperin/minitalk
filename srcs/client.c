/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:21:56 by aperin            #+#    #+#             */
/*   Updated: 2022/11/30 21:55:36 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "ft_printf.h"
#include <sys/types.h>
#include <signal.h>

int	main(int ac, char **av)
{
	pid_t	server_id;

	if (ac < 3)
		ft_printf("Not enough input arguments\n");
	else if (ac > 3)
		ft_printf("Too many input arguments\n");
	else
	{
		server_id = ft_atoi(av[1]);
		kill(server_id, SIGUSR1);
	}
}