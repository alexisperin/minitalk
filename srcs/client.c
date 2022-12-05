/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:21:56 by aperin            #+#    #+#             */
/*   Updated: 2022/12/05 13:10:20 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "ft_printf.h"
#include <sys/types.h>
#include <signal.h>

static char	*string_to_binary(char *str)
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
			binary[(i * CHAR_BIT) + j] = (str[i] >> (CHAR_BIT - 1 - j) & 1);
			binary[(i * CHAR_BIT) + j] += 48;
			j++;
		}
		i++;
	}
	binary[i * CHAR_BIT] = 0;
	return (binary);
}

static void	send_message(pid_t server_id, char *binary)
{
	size_t	i;
	int		ret;

	i = 0;
	while (binary[i])
	{
		if (binary[i] == '0')
			ret = kill(server_id, SIGUSR1);
		else
			ret = kill(server_id, SIGUSR2);
		if (ret == -1)
		{
			ft_printf("Message could not be sent\n");
			return ;
		}
		i++;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	pid_t	server_id;
	char	*binary;

	if (ac < 3)
		ft_printf("Not enough input arguments\n");
	else if (ac > 3)
		ft_printf("Too many input arguments\n");
	else
	{
		server_id = ft_atoi(av[1]);
		binary = string_to_binary(av[2]);
		if (!binary)
			exit(EXIT_FAILURE);
		send_message(server_id, binary);
		free(binary);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}
