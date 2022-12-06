# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperin <aperin@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 17:45:40 by aperin            #+#    #+#              #
#    Updated: 2022/12/06 13:10:35 by aperin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minitalk

CLIENT		= client
SERVER		= server

S_FILES		= server.c

C_FILES		= client.c ft_atoi.c
				
SRCS_DIR	= srcs
OBJSDIR		= objs
INCDIR		= includes ${FT_PRINTF_DIR}/includes

S_SRCS		= $(addprefix ${SRCS_DIR}/, ${S_FILES})
S_OBJS		= $(addprefix ${OBJSDIR}/, $(addsuffix .o, $(basename ${S_FILES})))
S_OBJS_DIR	= $(sort $(dir $(S_OBJS)))

C_SRCS		= $(addprefix ${SRCS_DIR}/, ${C_FILES})
C_OBJS		= $(addprefix ${OBJSDIR}/, $(addsuffix .o, $(basename ${C_FILES})))
C_OBJS_DIR	= $(sort $(dir $(C_OBJS)))

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCS		= $(foreach d, $(INCDIR), -I$d)

# ft_printf
FT_PRINTF_DIR	= srcs/ft_printf
FT_PRINTF		= ${FT_PRINTF_DIR}/libftprintf.a

# Rules
${OBJSDIR}/%.o: ${SRCS_DIR}/%.c
			@mkdir -p ${OBJSDIR} ${S_OBJS_DIR} ${C_OBJS_DIR}
			${CC} ${CFLAGS} ${INCS} -c -o $@ $<

all:		${NAME}

${NAME}:	${SERVER} ${CLIENT}
			

${SERVER}:	${S_OBJS}
			@make -C ${FT_PRINTF_DIR}
			${CC} ${S_OBJS} ${FT_PRINTF} -o ${SERVER}

${CLIENT}:	${C_OBJS}
			@make -C ${FT_PRINTF_DIR}
			${CC} ${C_OBJS} ${FT_PRINTF} -o ${CLIENT}

clean:
			@make clean -C ${FT_PRINTF_DIR}
			rm -rf ${OBJSDIR}

fclean:		clean
			@make fclean -C ${FT_PRINTF_DIR}
			rm -f ${CLIENT}
			rm -f ${SERVER}

re:			fclean all

.PHONY:		all clean fclean re NAME SERVER CLIENT