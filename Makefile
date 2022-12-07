# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperin <aperin@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 17:45:40 by aperin            #+#    #+#              #
#    Updated: 2022/12/07 10:18:05 by aperin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minitalk

CLIENT		= client
SERVER		= server

CLIENT_B	= client_bonus
SERVER_B	= server_bonus

S_FILES		= server.c

C_FILES		= client.c ft_atoi.c

S_FILES_B	= server_bonus.c

C_FILES_B	= client_bonus.c ft_atoi.c
				
SRCS_DIR	= srcs
OBJSDIR		= objs
INCDIR		= includes ${FT_PRINTF_DIR}/includes

S_SRCS		= $(addprefix ${SRCS_DIR}/, ${S_FILES})
S_OBJS		= $(addprefix ${OBJSDIR}/, $(addsuffix .o, $(basename ${S_FILES})))
S_OBJS_DIR	= $(sort $(dir $(S_OBJS)))

C_SRCS		= $(addprefix ${SRCS_DIR}/, ${C_FILES})
C_OBJS		= $(addprefix ${OBJSDIR}/, $(addsuffix .o, $(basename ${C_FILES})))
C_OBJS_DIR	= $(sort $(dir $(C_OBJS)))

S_SRCS_B		= $(addprefix ${SRCS_DIR}/, ${S_FILES_B})
S_OBJS_B		= $(addprefix ${OBJSDIR}/, $(addsuffix .o, $(basename ${S_FILES_B})))
S_OBJS_DIR_B	= $(sort $(dir $(S_OBJS_B)))

C_SRCS_B		= $(addprefix ${SRCS_DIR}/, ${C_FILES_B})
C_OBJS_B		= $(addprefix ${OBJSDIR}/, $(addsuffix .o, $(basename ${C_FILES_B})))
C_OBJS_DIR_B	= $(sort $(dir $(C_OBJS_B)))

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

bonus:		${C_OBJS_B} ${S_OBJS_B}
			@make -C ${FT_PRINTF_DIR}
			${CC} ${C_OBJS_B} ${FT_PRINTF} -o ${CLIENT_B}
			${CC} ${S_OBJS_B} ${FT_PRINTF} -o ${SERVER_B}

clean:
			@make clean -C ${FT_PRINTF_DIR}
			rm -rf ${OBJSDIR}

fclean:		clean
			@make fclean -C ${FT_PRINTF_DIR}
			rm -f ${CLIENT} ${SERVER} ${CLIENT_B} ${SERVER_B}

re:			fclean all

.PHONY:		all clean fclean re NAME SERVER CLIENT