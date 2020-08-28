/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deltetro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:17:53 by sassassi          #+#    #+#             */
/*   Updated: 2019/10/15 19:55:53 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_deltetro(t_tetromino **tmp)
{
	int	j;

	j = 0;
	if (tmp != NULL)
	{
		while ((*tmp)->m[j])
		{
			free((*tmp)->m[j]);
			(*tmp)->m[j] = NULL;
			j++;
		}
		free((*tmp)->m);
		(*tmp)->m = NULL;
		free(*tmp);
		tmp = NULL;
	}
}
