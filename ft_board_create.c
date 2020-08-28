/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:53:43 by sassassi          #+#    #+#             */
/*   Updated: 2019/10/15 19:06:58 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_board_in_alloc(int *j, char **board, int size,
		t_tetromino **begin)
{
	int		i;

	i = 0;
	board[*j] = (char*)malloc(sizeof(char) * (size + 1));
	if (board[*j] == NULL)
	{
		ft_del_board(board);
		ft_deltetro_list(begin);
		ft_error();
	}
	while (i < size)
	{
		board[*j][i] = '.';
		i++;
	}
	board[*j][i] = '\0';
	(*j)++;
}

char		**ft_board_create(int size, t_tetromino **begin)
{
	char	**board;
	int		j;

	j = 0;
	if (size != 0)
	{
		board = (char**)malloc(sizeof(char*) * (size + 1));
		if (board == NULL)
		{
			ft_deltetro_list(begin);
			ft_error();
		}
		while (j < size)
			ft_board_in_alloc(&j, board, size, begin);
		board[j] = NULL;
		return (board);
	}
	return (NULL);
}
