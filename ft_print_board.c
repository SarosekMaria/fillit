/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_board.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:33:48 by sassassi          #+#    #+#             */
/*   Updated: 2019/10/15 18:38:58 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_board(char **board, int board_size)
{
	int	j;

	j = 0;
	while (j < board_size)
	{
		write(1, board[j], board_size);
		write(1, "\n", 1);
		j++;
	}
}
