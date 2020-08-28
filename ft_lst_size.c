/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:02:51 by sassassi          #+#    #+#             */
/*   Updated: 2019/10/09 14:08:36 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_lst_size(t_tetromino **begin)
{
	t_tetromino	*tmp;
	int			count;

	count = 0;
	tmp = *begin;
	if (begin != NULL)
	{
		while (tmp)
		{
			count++;
			tmp = tmp->next;
		}
	}
	return (count);
}
