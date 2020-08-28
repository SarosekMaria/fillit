/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_correct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:04:22 by sassassi          #+#    #+#             */
/*   Updated: 2019/10/15 18:28:07 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_correct(char *c, char *letter)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] == '#')
			c[i] = *letter;
		i++;
	}
	(*letter)++;
}
