/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdmytro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 13:23:35 by mdmytro           #+#    #+#             */
/*   Updated: 2017/12/17 13:24:40 by mdmytro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define THIRD_COL(x, n) x[n + 3] == '#' && (x[n - 2] == '#' || x[n + 4] == '#')
#define FOURT_COL(x, n) x[n + 4] == '#' && (x[n - 1] == '#' || x[n + 5] == '#')

int				val_tetris(char *str, int c, int n, int p)
{
	c = 0;
	while (n < p)
	{
		if (str[n] == '#')
		{
			if (c == 0)
				c++;
			if (c == 4)
				break ;
			if (str[n + 1] == '#' && c++)
				n++;
			else if (THIRD_COL(str, n) && c++)
				n += 3;
			else if (FOURT_COL(str, n) && c++)
				n += 4;
			else if (str[n + 5] == '#' && c++)
				n += 5;
			else
				error();
		}
		else
			n++;
	}
	return (1);
}

int				ft_strlenf(char *str, int n, int p)
{
	int			i;

	i = 0;
	while (n < p)
		if (str[n++] != '0')
			i++;
	return (i);
}

char			*val_figure(char *str, int n, int p, char a)
{
	int			j;
	int			c;
	char		*mal;

	c = 0;
	j = 0;
	if (!(val_tetris(str, c, n, p)))
		error();
	str = figure_cut(str, n);
	if (!(mal = (char *)malloc(ft_strlenf(str, n, p) + 1)))
		error();
	while (n < p)
	{
		if (str[n] == '#')
			str[n] = a;
		if (str[n] != '0')
			mal[j++] = str[n];
		n++;
	}
	if (mal[j - 1] == '\n')
		mal[j - 1] = '\0';
	else
		mal[j] = '\0';
	return (mal);
}

int				row_count(char *str)
{
	int			c;
	int			j;
	int			f;

	c = 0;
	j = 0;
	f = 0;
	while (str[c])
	{
		if (str[c] == '#')
			f++;
		if (str[c] == '\n' && (str[c + 1] == '\n' || str[c + 1] == '\0'))
		{
			if (f != 4)
				error();
			else
				j++;
			f = 0;
		}
		c++;
	}
	return (j);
}

char			**val_cut(char *str)
{
	int			i;
	int			c;
	char		a;
	char		**tmp;

	i = 0;
	c = 0;
	a = 'A';
	if (!(tmp = (char **)malloc(sizeof(char *) * (row_count(str) + 1))))
		error();
	while (str[i] && a <= 'Z')
	{
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
			tmp[c++] = val_figure(str, i - 19, i, a++);
		i++;
	}
	tmp[c] = NULL;
	return (tmp);
}
