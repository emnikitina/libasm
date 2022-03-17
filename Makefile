# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odomenic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/29 19:00:10 by odomenic          #+#    #+#              #
#    Updated: 2021/04/02 18:29:41 by odomenic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM = nasm
FLAGS = -f macho64
SRCS = ft_strlen.s \
	   ft_strcpy.s \
	   ft_strcmp.s \
	   ft_write.s \
	   ft_read.s \
	   ft_strdup.s
OBJS = $(SRCS:.s=.o)
RM = rm -f
NAME = libasm.a

%.o: %.s  libasm.h
	$(ASM) $(FLAGS) $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

test:
	gcc -Wall -Werror -Wextra main.c $(NAME)
	./a.out

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME) $(OBJS)

re: fclean all
