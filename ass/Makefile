# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmansou <ahmansou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 14:48:59 by ahmansou          #+#    #+#              #
#    Updated: 2020/03/03 13:12:33 by ahmansou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ass

SRCS =  src/ass.c\
		src/get_next_line.c\
		src/main.c\
		src/label.c\
		src/misc.c\
		src/parser.c src/parser_misc.c\
		src/ft_split_whitespaces.c\
		src/ops.c src/ops_misc.c

OBJS = $(SRCS:.c=.o) 

FLG = -g -Wall -Werror -Wextra

$(NAME): $(OBJS)
	make -C ../libft
	make -C ../ft_printf
	gcc -g -o $(NAME) $(FLG) $(OBJS) ../libft/libft.a ../ft_printf/libftprintf.a

# $(OBJS): %.o:%.c
# 	gcc -c $(FLG) $^ -o $@

clean:
	make clean -C ../libft
	make clean -C ../ft_printf
	rm -f $(OBJS)

fclean: clean
	make fclean -C ../libft
	make fclean -C ../ft_printf
	rm -f $(NAME) 

re: fclean all

all : $(NAME)

