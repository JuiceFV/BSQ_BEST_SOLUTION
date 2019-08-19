
#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "ft_bitset.h"
# include "funcs.h"
# include "ft_iostream.h"

// in our case (example):
// g_full is 'x'
// g_obstacle is 'o'
// g_empty is '.'
// g_number_of_lines is '9'
// g_str only one string
char	g_full;
char	g_obstacle;
char	g_empty;
int		g_number_of_lines;
int		g_x;
int		g_y;
int		g_numlongs;
int		g_search_size;
char	*g_str;
char	g_first[13];
t_bitset	*g_map;

void	solve(t_bitset **map);
int		store_map(t_bitset ***map, char *file);
void	check_existence(int existence, t_bitset **map);
void	set_globals(char *str, int i);

#endif
