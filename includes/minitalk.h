/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:41:53 by aperin            #+#    #+#             */
/*   Updated: 2022/12/07 11:43:25 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# ifndef CHAR_BIT
#  define CHAR_BIT 8
# endif

# define BUFFER_SIZE 500

# include <stdlib.h>
# include <sys/types.h>
# include <signal.h>
# include "ft_printf.h"

int		ft_atoi(const char *str);

#endif