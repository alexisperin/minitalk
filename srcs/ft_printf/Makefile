# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperin <aperin@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 08:50:00 by aperin            #+#    #+#              #
#    Updated: 2022/11/29 17:44:40 by aperin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/ft_printf.c srcs/ft_printf_utils.c

OBJS	= $(SRCS:.c=.o)

NAME	= libftprintf.a

%.o : %.c
			gcc -Wall -Wextra -Werror -I ./includes -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar -rcs $(NAME) $(OBJS)

all:		${NAME}

clean:
			rm -f ${OBJS} $(B_OBJS)

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
