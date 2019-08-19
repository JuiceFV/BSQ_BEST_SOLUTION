#include "bitset_func.h"
#include "bsq.h"

void		bs_and(t_bitset *set1, t_bitset *set2)
{
	int i;

	i = 0;
	while (i < g_numlongs)
	{
		set1[i] &= set2[i];
		i++;
	}
}

t_bitset	*bs_copy(t_bitset *set)
{
	t_bitset	*output;
	int			i;

	output = (t_bitset *)malloc(sizeof(t_bitset) * g_numlongs);
	i = 0;
	while (i < g_numlongs)
	{
		output[i] = set[i];
		i++;
	}
	return (output);
}

void		bs_shift(unsigned long **bits)
{
	int i;

	i = 0;
	while (i < g_numlongs - 1)
	{
		(*bits)[i] &= ((*bits)[i] << 1) | (((*bits)[i + 1] >> 63) & 1);
		++i;
	}
	(*bits)[g_numlongs - 1] &= (*bits)[g_numlongs - 1] << 1;
}

int			existence(t_bitset *set, int line)
{
	int				i;
	int				j;
	unsigned long	temp;

	i = 0;
	temp = 0;
	while (i < g_numlongs && !temp)
		temp = (set[i++]);
	j = 0;
	while (temp && j < 64)
	{
		if (temp & (((t_bitset)1 << 63) >> j))
		{
			g_x = (i - 1) * 64 + j;
			g_y = line;
			return (1);
		}
		++j;
	}
	return (0);
}
