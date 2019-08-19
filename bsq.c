
#include "bsq.h"
#include "bitset_func.h"

int g_i;
int g_l;
int g_k;

void	solve(t_bitset **map)
{
	int s;

	g_i = 0;
	g_l = 0;
	g_k = 0;
	g_search_size = 1;
	while (g_i + g_search_size <= g_number_of_lines)
	{
		while (g_l < g_search_size - 1)
			bs_shift(&(map[g_i + g_l++]));
		while (g_k < g_search_size - 1)
		{
			bs_shift(&(map[g_i + g_search_size - 1]));
			g_k++;
		}
		s = 1;
		while (s < g_search_size)
			bs_and(map[g_i], map[g_i + s++]);
		check_existence(existence(map[g_i], g_i), map);
	}
}

void	check_existence(int existence, t_bitset **map)
{
	int p;

	if (existence)
	{
		g_l = 0;
		g_k = 0;
		g_search_size++;
	}
	else
	{
		g_i++;
		p = 0;
		while (g_i + g_search_size <= g_number_of_lines && p < g_search_size - 1)
		{
			if (g_i + g_search_size <= g_number_of_lines)
				bs_shift(&(map[g_i + g_search_size - 1]));
			p++;
		}
	}
}

void	set_globals(char *str, int i)
{
	int digits;
	int n;

	if (i > 3)
	{
		g_full = str[i - 1];
		g_obstacle = str[i - 2];
		g_empty = str[i - 3];
		str[i - 3] = '\0';
		g_number_of_lines = ft_specified_atoi(str);
		digits = 1;
		n = g_number_of_lines;
//		if (n < 0)
//			n *= -1;
		while (n >= 10)
		{
			n /= 10;
			++digits;
		}
		if (digits + 3 != i || g_obstacle == g_empty || g_obstacle == g_full || g_full == g_empty)
			g_number_of_lines = 0;
	}
}

int		store_map(t_bitset ***map, char *file)
{
	int		i;
	char	c;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	while (read(fd, &c, 1) && c != '\n' && i < 13)
		g_first[i++] = c;
	set_globals(g_first, i);
	(*map) = (t_bitset **)malloc(sizeof(t_bitset *) * g_number_of_lines);
	(*map)[0] = init_first_line(fd);
	g_str = str_realloc(&g_str, (g_len + 1) * g_number_of_lines);
	if ((*map)[0] && g_len > 0)
	{
		i = 0;
		while (++i < g_number_of_lines)
			(*map)[i] = init_bitset(fd, (g_len + 1) * i);
	}
	if (g_str[(g_len + 1) * i - 1] != '\n')
		return (0);
	close(fd);
	return (check_error(*map));
}

int		main(int argc, char *argv[])
{
	t_bitset	**map;
	int			i;

	map = (void *)0;
	i = 1;
	if (argc == 1)
		input(&map);
	while (i < argc)
	{
		if (store_map(&map, argv[i]))
		{
			solve(map);
			add_full_chars();
			write(1, g_str, g_number_of_lines * (g_len + 1));
			free(g_str);
		}
		else
			print_error();
		++i;
		if (argc > 2)
			ft_putchar('\n', 1);
	}
	return (0);
}
