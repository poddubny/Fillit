/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoddubn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 04:45:50 by mpoddubn          #+#    #+#             */
/*   Updated: 2018/01/24 04:46:04 by mpoddubn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

void		error();
void		ft_putchar(char c);
void		ft_putstr(char const *s);
void		ft_memdel(void **ap);
int			delete_figure(char a, char *map, int q);
char		search_char(char *str);
int			val_tetris(char *str, int c, int n, int p);
int			ft_strlenf(char *str, int n, int p);
char		*val_figure(char *str, int n, int p, char a);
int			row_count(char *str);
char		**val_cut(char *str);
int			insert_figure(int c, char *str, char *map, int p);
int			map_count(char *map);
int			map_next(char *map, int *n, int *c, int *x);
int			*audit(char **str, char *map, int y, int c);
char		*backtrack(char **str, char *map, int m);
int			map_root(char **figures);
char		*map_print(char **figures, int m);
char		*figure_cut_vrtcl(char *str, int n);
char		*figure_cut_hrznl(char *str, int n);
char		*figure_cut(char *str, int n);
char		*val_file(char *str);
char		*readfile(char *str);
int			main(int argc, char **argv);
int			count_s(char **str);

#endif
