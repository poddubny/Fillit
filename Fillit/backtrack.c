/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdmytro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 20:27:57 by mdmytro           #+#    #+#             */
/*   Updated: 2018/01/20 20:28:03 by mdmytro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				insert_figure(int c, char *str, char *map, int p)
{
	int			x;
	int			j;
	int			i;

	x = 0;
	i = 0;
	j = c;
	while (str[x])
	{
		if (str[x] == '\n' && ++i)
		{
			c = j + p * i;
			if (map[c] != '.')
				x++;
			else
				map[c] = str[x += 1];
		}
		else if (map[c] != '.' && str[x] == '.' && ++x)
			c++;
		else
			map[c++] = str[x++];
	}
	return (0);
}

int				map_count(char *map)
{
	int			c;
	int			p;

	c = 0;
	p = 0;
	while (map[c++] != '\n')
		p++;
	p++;
	return (p);
}

int				map_next(char *map, int *n, int *c, int *x)
{
	int			i;

	i = 0;
	if (map[*c + 1] == '\n')
		*n = *c += 2;
	else
		*n = *c += 1;
	*x = 0;
	return (i);
}

int				*audit(char **str, char *map, int y, int c)
{
	int			x;
	int			i;
	int			n;
	int			*d;

	d = (int*)malloc(sizeof(int) * 2);
	x = 0;
	i = 0;
	n = c;
	while (str[y][x])
	{
		if (str[y][x] == '\n' && ++i && x++)
			n = c + map_count(map) * i;
		else if (map[n] != '.' && str[y][x] != '.')
			i = map_next(map, &n, &c, &x);
		else if (++x)
			n++;
		if (!map[n] && str[y][x])
			break ;
	}
	d[0] = x;
	d[1] = c;
	return (d);
}

char			*backtrack(char **str, char *map, int m)
{
	int		c;
	int		y;
	int		x;
	int		*d;
	int		cordinate[count_s(str)];

	c = 0;
	y = 0;
	while (str[y])
	{
		d = audit(str, map, y, c);
		x = d[0];
		c = d[1];
		if (!str[y][x] && ((cordinate[y] = c) || 1))
			c = insert_figure(c, str[y++], map, map_count(map));
		else if (y == 0 && ++m)
		{
			ft_memdel((void **)&map);
			map = backtrack(str, map_print(str, m), m);
			break ;
		}
		else if (y--)
			c = delete_figure(search_char(str[y]), map, cordinate[y]) + 1;
	}
	return (map);
}
