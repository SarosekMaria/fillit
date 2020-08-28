/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:40:42 by sassassi          #+#    #+#             */
/*   Updated: 2019/10/15 20:27:28 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_miss_dot(t_tetromino *t, int *j_m, int *i_m, int *f)
{
	*f = 0;
	while (t->m[*j_m][*i_m] == '.')
	{
		(*i_m)++;
		if (t->m[0][0] == '.' && (*j_m) == 0)
			(*f)++;
	}
}

int		ft_check_size(char **b, t_tetromino *t, int j, int i)
{
	int	b_s;

	b_s = ft_board_size(b);
	if (((t->w > b_s - i) && t->m[0][0] != '.') || t->h > b_s - j)
		return (1);
	return (0);
}

int		ft_check_place(char **b, t_tetromino *t, int j, int i)
{
	int	j_m;
	int	i_m;
	int	f;

	if ((j_m = ft_check_size(b, t, j, i)) == 1)
		return (1);
	while (j_m < t->h)
	{
		i_m = 0;
		while (i_m < t->w)
		{
			ft_miss_dot(t, &j_m, &i_m, &f);
			while (t->m[j_m][i_m] == t->l)
			{
				if ((b[j + j_m][i + i_m - f] != '.') && (b[j + j_m][i + i_m - f]
							!= t->l))
					return (1);
				i_m++;
			}
			i -= f;
			break ;
		}
		j_m++;
	}
	return (0);
}
