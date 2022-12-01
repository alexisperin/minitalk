/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:21:56 by aperin            #+#    #+#             */
/*   Updated: 2022/12/01 08:25:31 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "ft_printf.h"
#include <sys/types.h>
#include <signal.h>

char	*string_to_binary(char *str)
{
	char	*binary;
	size_t	i;
	int		j;
	size_t	len;

	len = ft_strlen(str);
	binary = malloc((len + 1) * CHAR_BIT);
	if (!binary)
		return (0);
	i = 0;
	while (i <= len)
	{
		j = 0;
		while (j < CHAR_BIT)
		{
			binary[(i * CHAR_BIT) + j] = (str[i] >> (CHAR_BIT - 1 - j) & 1) + 48;
			j++;
		}
		i++;
	}
	return (binary);
}
#include <stdio.h>
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
		printf("%s\n", string_to_binary(av[2]));
		exit(EXIT_SUCCESS);
	}
}
