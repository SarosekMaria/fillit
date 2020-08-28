/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_det_tetromino.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:31:03 by sassassi          #+#    #+#             */
/*   Updated: 2019/10/15 20:38:31 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	g_i;
int	g_j;
int	g_max_w;
int	g_min_w;
int	g_flag;

int	ft_det_tetromino(int *j_flag, char *c, int *w, int *height)
{
	g_j = 0;
	g_max_w = -1;
	g_min_w = -1;
	while (g_j < 4)
	{
		g_i = 0;
		g_flag = 0;
		while (g_i < 4)
		{
			if (c[g_j * 5 + g_i] != '.')
			{
				(g_min_w == -1 && g_max_w == -1) ? (*j_flag) = g_j : g_flag++;
				(g_min_w == -1) ? (g_min_w = g_i) : g_flag++;
				(g_min_w > g_i) ? (g_min_w = g_i) : g_flag++;
				(g_max_w < g_i) ? g_max_w = g_i : g_flag++;
			}
			g_i++;
		}
		(*w < g_max_w - g_min_w + 1) ? *w = g_max_w - g_min_w + 1 : g_i++;
		(g_flag > 0) ? (*height)++ : g_i++;
		g_j++;
	}
	return (g_min_w);
}
