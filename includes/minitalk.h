/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:41:53 by aperin            #+#    #+#             */
/*   Updated: 2022/12/06 10:42:19 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# ifndef CHAR_BIT
#  define CHAR_BIT 8
# endif

# define BUFFER_SIZE 1000

# include <stdlib.h>

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);

#endif