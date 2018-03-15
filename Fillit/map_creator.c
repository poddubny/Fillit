/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdmytro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:16:51 by mdmytro           #+#    #+#             */
/*   Updated: 2017/12/14 13:17:14 by mdmytro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			map_root(char **figures)
{
	int		i;
	int		j;

	i = 0;
	j = 2;
	while (figures[i])
		i++;
	i *= 4;
	while (j * j < i)
		j++;
	return (j);
}

char		*map_print(char **figures, int m)
{
	int		i;
	int		j;
	int		z;
	char	*mp;

	i = map_root(figures) + m;
	mp = (char *)malloc(i * (i + 1));
	j = 0;
	z = 1;
	while (z < (i + 1))
	{
		while (j < ((i + 1) * z) - 1)
			mp[j++] = '.';
		z++;
		if (z == (i + 1))
			mp[j] = '\0';
		else
			mp[j++] = '\n';
	}
	return (mp);
}
