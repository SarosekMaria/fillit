/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:47:10 by sassassi          #+#    #+#             */
/*   Updated: 2019/10/15 20:33:50 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

void					ft_error(void);
typedef struct			s_tetromino
{
	int					h;
	int					w;
	char				l;
	char				**m;
	struct s_tetromino	*next;
}						t_tetromino;
t_tetromino				*ft_make_tetrolist(char *argv);
void					ft_deltetro(t_tetromino **tmp);
void					ft_apend_tetro(t_tetromino **begin,
		t_tetromino *new);
int						ft_lst_size(t_tetromino **begin);
int						ft_sqrt(int a);
char					**ft_solution(t_tetromino *begin);
void					ft_correct(char *c, char *letter);
void					ft_deltetro_list(t_tetromino **begin);
void					ft_print_board(char **board, int board_size);
int						ft_board_size(char **board);
void					ft_del_board(char **board);
void					ft_mal_tetromino_error(t_tetromino *new, int j);
char					**ft_board_create(int size, t_tetromino **begin);
void					ft_pass(char **board, t_tetromino *tmp, int i, int j);
int						ft_check_place(char **board, t_tetromino *tmp,
		int j, int i);
int						ft_det_tetromino(int *j_flag, char *c,
		int *width, int *height);

#endif
