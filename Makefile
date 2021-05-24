# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkaruk-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 15:48:23 by jkaruk-m          #+#    #+#              #
#    Updated: 2021/05/24 14:51:14 by jkaruk-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PATH_SRCS = ./
PATH_HEADERS = ./

COMPILER_COMMAND = gcc
FLAGS = -Wall -Wextra -Werror
OPTIONS = -I${PATH_HEADERS}

LIB_CREATOR_COMMAND = ar
RM_COMMAND = rm -f

SRCS = ft_isalnum.c \
       		ft_isalpha.c \
       		ft_isascii.c \
       		ft_isdigit.c \
       		ft_isprint.c \
       		ft_strlen.c \
       		ft_strncmp.c \
       		ft_tolower.c \
       		ft_toupper.c \
       		ft_strlcpy.c \
       		ft_strlcat.c \
       		ft_atoi.c \
       		ft_strdup.c \
       		ft_bzero.c \
       		ft_calloc.c \
       		ft_strchr.c \
       		ft_strnstr.c \
       		ft_strrchr.c \
       		ft_memccpy.c \
       		ft_memchr.c \
       		ft_memcmp.c \
       		ft_memcpy.c \
       		ft_memmove.c \
       		ft_memset.c \
       		ft_putchar_fd.c \
       		ft_putstr_fd.c \
       		ft_putendl_fd.c \
       		ft_putnbr_fd.c \
       		ft_split.c \
       		ft_itoa.c \

BONUS = ${PATH_SRCS}/ft_lstadd_front.c ${PATH_SRCS}/ft_lstlast.c ${PATH_SRCS}/ft_lstadd_back.c\
 ${PATH_SRCS}/ft_lstdelone.c ${PATH_SRCS}/ft_lstclear.c ${PATH_SRCS}/ft_lstiter.c ${PATH_SRCS}/ft_lstmap.c\
 ${PATH_SRCS}/ft_lstnew.c ${PATH_SRCS}/ft_lstsize.c
OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS:.c=.o}

all: ${NAME}
.c.o: ${OBJS} ${BONUS_OBJS}
	${COMPILER_COMMAND} ${OPTIONS} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	${LIB_CREATOR_COMMAND} rc ${NAME} ${OBJS}

clean:
	${RM_COMMAND} ${OBJS} ${BONUS_OBJS}

fclean: clean
	${RM_COMMAND} ${NAME}

re: fclean all

bonus: ${OBJS} ${BONUS_OBJS}
	${LIB_CREATOR_COMMAND} rc ${NAME} ${OBJS} ${BONUS_OBJS}
