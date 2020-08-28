/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:37:04 by sassassi          #+#    #+#             */
/*   Updated: 2019/10/19 17:35:20 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_try(t_tetromino *tmp, char **board)
{
	int			i;
	int			j;
	int			flag;

	j = 0;
	while (board[j])
	{
		i = 0;
		while (board[j][i])
		{
			if (board[j][i] == '.')
			{
				flag = ft_check_place(board, tmp, j, i);
				if (flag == 0)
				{
					ft_pass(board, tmp, i, j);
					return (1);
				}
			}
			i++;
		}
		j++;
	}
	return (0);
}

void			ft_undo(t_tetromino *tmp, char **board)
{
	int			i;
	int			j;
	int			count;

	j = 0;
	count = 0;
	while (board[j] && count != 4)
	{
		i = 0;
		while (board[j][i] && count != 4)
		{
			if (board[j][i] == tmp->l)
			{
				board[j][i] = '.';
				count++;
			}
			i++;
		}
		j++;
	}
}

int				ft_move(t_tetromino *tmp, char **b)
{
	int			i;
	int			j;
	int			f;

	f = 0;
	j = 0;
	while (b[j])
	{
		i = 0;
		while (b[j][i])
		{
			if (b[j][i] == tmp->l && f == 0)
				f = 1;
			else if (((b[j][i] == '.') || (b[j][i] == tmp->l)) && (f == 1))
				if (ft_check_place(b, tmp, j, i) == 0)
				{
					ft_undo(tmp, b);
					ft_pass(b, tmp, i, j);
					return (1);
				}
			i++;
		}
		j++;
	}
	return (0);
}

char			**ft_search(t_tetromino *begin, char **board)
{
	if (begin == NULL)
		return (board);
	if (ft_try(begin, board) == 1)
	{
		if (ft_search(begin->next, board) == NULL)
			while (1)
			{
				if (ft_move(begin, board) == 1)
				{
					if (ft_search(begin->next, board) == NULL)
						continue ;
					else
						break ;
				}
				else
				{
					ft_undo(begin, board);
					return (NULL);
				}
			}
	}
	else
		return (NULL);
	return (board);
}

char			**ft_solution(t_tetromino *begin)
{
	char		**board;
	int			board_size;
	t_tetromino	*tmp;

	tmp = begin;
	if (ft_lst_size(&begin) > 26)
		ft_error();
	board_size = ft_sqrt(ft_lst_size(&begin) * 4);
	board = ft_board_create(board_size, &begin);
	while (1)
	{
		if (ft_search(tmp, board) == NULL)
		{
			board_size++;
			ft_del_board(board);
			board = ft_board_create(board_size, &begin);
		}
		else
			break ;
	}
	ft_deltetro_list(&begin);
	return (board);
}
