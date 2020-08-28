/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_tetrolist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:32:17 by sassassi          #+#    #+#             */
/*   Updated: 2019/10/15 20:39:33 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetromino		*ft_mal_tetromino(int width, int height, char letter)
{
	t_tetromino	*new;
	int			j;

	j = 0;
	new = (t_tetromino*)malloc(sizeof(t_tetromino) * 1);
	if (new == NULL)
		ft_error();
	new->w = width;
	new->h = height;
	new->m = (char**)malloc(sizeof(char*) * (height + 1));
	if (new->m == NULL)
	{
		free(new);
		ft_error();
	}
	while (j < height)
	{
		new->m[j] = (char*)malloc(sizeof(char) * (width + 1));
		ft_mal_tetromino_error(new, j);
		j++;
	}
	new->l = letter - 1;
	new->next = NULL;
	return (new);
}

void			ft_new_tetromino(t_tetromino *tmp, int j_flag, int min_w,
		char *c)
{
	int			i;
	int			j;

	j = 0;
	while (j < tmp->h)
	{
		i = 0;
		while (i < tmp->w)
		{
			tmp->m[j][i] = c[(j + j_flag) * 5 + (min_w + i)];
			i++;
		}
		tmp->m[j][i] = '\0';
		j++;
	}
	tmp->m[j] = NULL;
}

t_tetromino		*ft_tetro_init(char *c, char letter)
{
	int			j_flag;
	int			min_w;
	int			width;
	int			height;
	t_tetromino	*tmp;

	width = 0;
	height = 0;
	min_w = -1;
	j_flag = 0;
	min_w = ft_det_tetromino(&j_flag, c, &width, &height);
	tmp = ft_mal_tetromino(width, height, letter);
	ft_new_tetromino(tmp, j_flag, min_w, c);
	return (tmp);
}

t_tetromino		*ft_make_tetrolist(char *argv)
{
	int			fd;
	int			ret;
	char		letter;
	char		c[21];
	t_tetromino	*begin;

	letter = 'A';
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error();
	if (!read(fd, c, 21))
		ft_error();
	c[20] = '\0';
	ft_correct(c, &letter);
	begin = ft_tetro_init(c, letter);
	while ((ret = read(fd, c, 21)) > 0)
	{
		c[20] = '\0';
		ft_correct(c, &letter);
		ft_apend_tetro(&begin, ft_tetro_init(c, letter));
	}
	if (ret < 0)
		ft_error();
	return (begin);
}
