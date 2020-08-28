/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deltetro_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:25:14 by sassassi          #+#    #+#             */
/*   Updated: 2019/10/13 22:01:18 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_deltetro_list(t_tetromino **begin)
{
	t_tetromino	*tmp;

	if (begin != NULL)
	{
		if ((*begin)->next)
		{
			while ((*begin)->next)
			{
				tmp = (*begin)->next;
				ft_deltetro(begin);
				*begin = tmp;
			}
		}
		ft_deltetro(begin);
		*begin = NULL;
	}
}
