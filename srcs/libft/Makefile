# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 20:49:09 by bcolossu          #+#    #+#              #
#    Updated: 2020/12/03 18:54:08 by rczarfun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: $(NAME) all compile fclean clean re

NAME = libft.a

SRCS =	ft_atoi.c \
	ft_lstnew.c \
	ft_putendl_fd.c \
	ft_strequ.c \
	ft_strnew.c \
	ft_bzero.c \
	ft_memalloc.c \
	ft_putnbr.c \
	ft_striter.c \
	ft_strnstr.c \
	ft_isalnum.c \
	ft_memccpy.c \
	ft_putnbr_fd.c \
	ft_putnbrmax.c \
	ft_putnbrmax_u.c \
	ft_striteri.c \
	ft_strrchr.c \
	ft_isalpha.c \
	ft_memchr.c \
	ft_putstr.c \
	ft_strjoin.c \
	ft_strsplit.c \
	ft_isascii.c \
	ft_memcmp.c \
	ft_putstr_fd.c \
	ft_strlcat.c \
	ft_strstr.c \
	ft_isdigit.c \
	ft_memcpy.c \
	ft_strcat.c \
	ft_strlen.c \
	ft_strsub.c \
	ft_isprint.c \
	ft_memdel.c \
	ft_strchr.c \
	ft_strmap.c \
	ft_strtrim.c \
	ft_itoa.c \
	ft_memmove.c \
	ft_strclr.c \
	ft_strmapi.c \
	ft_tolower.c \
	ft_lstadd.c \
	ft_memset.c \
	ft_strcmp.c \
	ft_strncat.c \
	ft_toupper.c \
	ft_lstdel.c \
	ft_putchar.c \
	ft_strcpy.c \
	ft_strncmp.c \
	ft_lstiter.c \
	ft_putendl.c \
	ft_strdup.c \
	ft_strnequ.c \
	ft_lstdelone.c \
	ft_putchar_fd.c \
	ft_strdel.c \
	ft_strncpy.c \
	ft_lstmap.c \
	ft_abs.c \
	ft_num_len.c \
	get_next_line.c\
	ft_num_split.c\
	ft_itoa_base.c \
	ft_strndup.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $^
		ranlib $(NAME)

$(OBJS): %.o : %.c libft.h get_next_line.h
		gcc -Wall -Wextra -Werror -I . -c $<

fclean: clean
		/bin/rm -f libft.a

clean:
		/bin/rm -f $(OBJS)

re: fclean all
