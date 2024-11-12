# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocroon <jocroon@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 11:02:23 by jocroon           #+#    #+#              #
#    Updated: 2024/11/12 12:23:10 by jocroon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =	ft_atoi.c				\
			ft_bzero.c				\
			ft_calloc.c				\
			ft_isalnum.c			\
			ft_isalpha.c			\
			ft_isascii.c			\
			ft_isdigit.c			\
			ft_isprint.c			\
			ft_itoa.c				\
			ft_memchr.c				\
			ft_memcmp.c				\
			ft_memcpy.c				\
			ft_memmove.c			\
			ft_memset.c				\
			ft_putchar_fd.c			\
			ft_putendl_fd.c			\
			ft_putnbr_fd.c			\
			ft_putstr_fd.c			\
			ft_split.c				\
			ft_strchr.c				\
			ft_strdup.c				\
			ft_striteri.c			\
			ft_strjoin.c			\
			ft_strlcat.c 			\
			ft_strlcpy.c			\
			ft_strlen.c 			\
			ft_strmapi.c			\
			ft_strncmp.c			\
			ft_strnstr.c			\
			ft_strrchr.c			\
			ft_strtrim.c			\
			ft_substr.c				\
			ft_tolower.c			\
			ft_toupper.c			\
			ft_int_len.c			\
			ft_unsigned_int_len.c	\
			ft_utoa.c				
INCLUDES = .
OBJECTS = $(SOURCES:%.c=%.o)
NAME = libft.a

CC = gcc
RM = rm -f
AR = ar rc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -c $(SOURCES) -I $(INCLUDES)
	$(AR) $(NAME) $(OBJECTS)

%.o: %c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re