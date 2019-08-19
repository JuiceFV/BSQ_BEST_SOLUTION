

#ifndef BITSET_UTILS_H
# define BITSET_UTILS_H

# include "ft_bitset.h"

t_bitset			*bs_copy(t_bitset *set);
void				bs_and(t_bitset *set1, t_bitset *set2);
void				bs_shift(unsigned long **bits);
int					existence(t_bitset *set, int line);

#endif
