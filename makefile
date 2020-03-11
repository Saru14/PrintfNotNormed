# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbodson <jbodson@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 17:13:25 by jbodson           #+#    #+#              #
#    Updated: 2020/02/29 16:23:49 by jbodson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_ifc.c ft_isdori.c ft_printf.c ft_ifs.c ft_ifx.c ft_ifp.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= cc

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

bonus:		${OBJS}
			ar rc ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
