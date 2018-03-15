/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdmytro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 14:19:55 by mdmytro           #+#    #+#             */
/*   Updated: 2017/12/17 14:20:42 by mdmytro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

void		ft_putstr(char const *s)
{
	int		i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
}

void		ft_memdel(void **ap)
{
	if (ap && *ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}

int			delete_figure(char a, char *map, int q)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (map[i] == a)
			map[i] = '.';
		i++;
	}
	return (q);
}

char		search_char(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			break ;
		i++;
	}
	return (str[i]);
}
