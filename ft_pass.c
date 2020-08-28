/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pass.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:27:52 by sassassi          #+#    #+#             */
/*   Updated: 2019/10/15 19:58:08 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_enum(int *f, t_tetromino *tmp, int *j_mas, int *i_mas)
{
	*f = 0;
	while (tmp->m[*j_mas][*i_mas] == '.')
	{
		(*i_mas)++;
		if (tmp->m[0][0] == '.' && (*j_mas) == 0)
			(*f)++;
	}
}

void	ft_pass(char **board, t_tetromino *tmp, int i, int j)
{
	int	i_mas;
	int	j_mas;
	int	f;

	j_mas = 0;
	while (j_mas < tmp->h)
	{
		i_mas = 0;
		while (i_mas < tmp->w)
		{
			ft_enum(&f, tmp, &j_mas, &i_mas);
			while (tmp->m[j_mas][i_mas] == tmp->l)
			{
				board[j + j_mas][i + i_mas - f] = tmp->l;
				i_mas++;
			}
			i -= f;
			break ;
		}
		j_mas++;
	}
}
