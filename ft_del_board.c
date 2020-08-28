/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:52:57 by sassassi          #+#    #+#             */
/*   Updated: 2019/10/15 18:37:47 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_del_board(char **board)
{
	int	j;

	j = 0;
	while (board[j])
	{
		free(board[j]);
		board[j] = NULL;
		j++;
	}
	free(board);
	board = NULL;
}
