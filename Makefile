# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sassassi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/12 14:24:17 by sassassi          #+#    #+#              #
#    Updated: 2019/10/15 20:33:24 by sassassi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c fillit.c ft_error.c ft_make_tetrolist.c ft_deltetro.c ft_apend_tetro.c ft_lst_size.c ft_solution.c ft_sqrt.c ft_correct.c ft_deltetro_list.c ft_print_board.c ft_board_size.c ft_del_board.c ft_mal_tetromino_error.c ft_board_create.c ft_pass.c ft_check_place.c ft_det_tetromino.c -g
	@gcc -Wall -Wextra -Werror -o $(NAME) fillit.o ft_error.o ft_make_tetrolist.o ft_deltetro.o ft_apend_tetro.o ft_lst_size.o ft_solution.o ft_sqrt.o ft_correct.o ft_deltetro_list.o ft_print_board.o ft_board_size.o ft_del_board.o ft_mal_tetromino_error.o ft_board_create.o ft_pass.o ft_check_place.o ft_det_tetromino.o -g

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
