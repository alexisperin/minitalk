/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:41:53 by aperin            #+#    #+#             */
/*   Updated: 2022/12/01 08:20:45 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# ifndef CHAR_BIT
#  define CHAR_BIT 8
# endif

# include <stdlib.h>

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);

#endif