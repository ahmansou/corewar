# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmansou <ahmansou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/23 15:45:30 by ahmansou          #+#    #+#              #
#    Updated: 2020/02/25 14:50:01 by ahmansou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRCS =  src/main.c

OBJS = $(SRCS:.c=.o) 

FLG = -g -Wall -Werror -Wextra

$(NAME): $(OBJS)
	make -C libft
	make -C ft_printf
	gcc -g -o $(NAME) $(FLG) $(OBJS) libft/libft.a ft_printf/libftprintf.a

$(OBJS): %.o:%.c
	gcc -c $(FLG) $^ -o $@

clean:
	make clean -C libft
	make clean -C ft_printf
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -f $(NAME) 

re: fclean all

all : $(NAME)

