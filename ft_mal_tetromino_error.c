/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mal_tetromino_error.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:48:07 by sassassi          #+#    #+#             */
/*   Updated: 2019/10/15 19:57:20 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_mal_tetromino_error(t_tetromino *new, int j)
{
	if (new->m[j] == NULL)
	{
		j--;
		while (j--)
			free(new->m[j]);
		free(new->m);
		free(new);
		ft_error();
	}
}
