/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_cut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdmytro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 13:06:19 by mdmytro           #+#    #+#             */
/*   Updated: 2017/12/17 13:07:14 by mdmytro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			*figure_cut_vrtcl(char *str, int n)
{
	if (str[n] == '.' && str[n + 5] == '.' && str[n + 10] == '.' && \
		str[n + 15] == '.')
	{
		str[n] = '0';
		str[n + 5] = '0';
		str[n + 10] = '0';
		str[n + 15] = '0';
	}
	return (str);
}

char			*figure_cut_hrznl(char *str, int n)
{
	if ((str[n] == '.' || str[n] == '0') \
		&& (str[n + 1] == '.' || str[n + 1] == '0') \
		&& (str[n + 2] == '.' || str[n + 2] == '0') \
		&& (str[n + 3] == '.' || str[n + 3] == '0'))
	{
		str[n] = '0';
		str[n + 1] = '0';
		str[n + 2] = '0';
		str[n + 3] = '0';
		if (str[n + 4] == '\n')
			str[n + 4] = '0';
	}
	return (str);
}

char			*figure_cut(char *str, int n)
{
	int		i;
	int		j;

	j = n;
	i = 4;
	while (i--)
		str = figure_cut_vrtcl(str, j++);
	i = 4;
	j = n;
	while (i--)
	{
		str = figure_cut_hrznl(str, j);
		j += 5;
	}
	return (str);
}

int				count_s(char **str)
{
	int			c;
	int			j;

	c = 0;
	j = 0;
	while (str[c])
		c++;
	return (c);
}
