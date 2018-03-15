/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdmytro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 14:22:23 by mdmytro           #+#    #+#             */
/*   Updated: 2017/12/17 14:22:54 by mdmytro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*val_file(char *str)
{
	int		i;
	int		c;
	int		p;

	i = 0;
	c = 4;
	p = 0;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			error();
		if (c == -1)
			c = 4;
		if (str[i + c] != '\n' || (str[i] == '\n' && str[i + 1] == '\n' && \
			p % 4))
			error();
		c--;
		i++;
		if (c == 0 && p++)
			if (!(p % 4))
				i++;
	}
	if (p % 4 || (i + 1) % 21)
		error();
	return (str);
}

char		*readfile(char *str)
{
	int		i;
	int		fd;
	char	c;
	char	*res;

	i = 0;
	fd = open(str, O_RDONLY);
	while (read(fd, &c, 1) == 1)
		i++;
	if (i > 545)
		error();
	close(fd);
	res = (char *)malloc(i + 1);
	i = 0;
	fd = open(str, O_RDONLY);
	while (read(fd, &c, 1) == 1)
		res[i++] = c;
	res[i] = '\0';
	return (res);
}

int			main(int argc, char **argv)
{
	char	*fd;
	char	*tr;
	char	*mp;
	char	**vc;

	if (argc == 2)
	{
		fd = readfile(argv[1]);
		vc = val_cut(val_file(fd));
		mp = map_print(vc, 0);
		tr = backtrack(vc, mp, 0);
		ft_putstr(tr);
	}
	else
		ft_putstr("Usage: ./fillit test_1");
	return (0);
}
