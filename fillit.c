/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:42:18 by sassassi          #+#    #+#             */
/*   Updated: 2019/10/15 18:26:58 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_simple_valid(int *fd)
{
	int		ret;
	int		i;
	int		count;
	char	c[6];

	count = 0;
	while (count < 4)
	{
		i = 0;
		ret = read(*fd, c, 5);
		(ret <= 0) ? ft_error() : (c[ret] = '\0');
		while (c[i + 1])
			(c[i] != '#' && c[i] != '.') ? ft_error() : i++;
		(c[i] != '\n') ? ft_error() : count++;
	}
	ret = read(*fd, c, 1);
	if (ret == 0)
		return (0);
	else if (ret < 0 || c[0] != '\n')
		ft_error();
	return (1);
}

void		ft_simbols_valid(int *i, char *c, int *count, int *sides)
{
	while (*i < 20)
	{
		if (c[*i] == '#')
		{
			(*count)++;
			if (*count > 4)
				ft_error();
			if (*i / 5 != 0)
				if (c[*i - 5] == '#')
					(*sides)++;
			if (*i % 5 != 0)
				if (c[*i - 1] == '#')
					(*sides)++;
			if ((*i + 1 % 5) != 0)
				if (c[*i + 1] == '#')
					(*sides)++;
			if (*i / 5 != 3)
				if (c[*i + 5] == '#')
					(*sides)++;
		}
		(*i)++;
	}
}

int			ft_block_valid(int *fd)
{
	int		sides;
	int		i;
	int		ret;
	int		count;
	char	c[21];

	i = 0;
	sides = 0;
	count = 0;
	ret = read(*fd, c, 20);
	if (ret != 20)
		ft_error();
	c[ret] = '\0';
	ft_simbols_valid(&i, c, &count, &sides);
	if (sides != 6 && sides != 8)
		ft_error();
	ret = read(*fd, c, 1);
	if (ret == 0)
		return (0);
	else if (ret < 0)
		ft_error();
	return (1);
}

void		ft_validator(char *argv)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error();
	while (1)
		if (ft_simple_valid(&fd) == 0)
			break ;
	close(fd);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error();
	while (1)
		if (ft_block_valid(&fd) == 0)
			break ;
	close(fd);
}

int			main(int argc, char **argv)
{
	char **board;

	if (argc == 2)
	{
		ft_validator(argv[1]);
		board = ft_solution(ft_make_tetrolist(argv[1]));
		ft_print_board(board, ft_board_size(board));
		ft_del_board(board);
	}
	else
		write(1, "Input requires only one argument\n", 33);
	return (0);
}
