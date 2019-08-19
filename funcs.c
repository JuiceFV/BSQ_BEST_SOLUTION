#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

int		ft_specified_atoi(char *str)
{
	int result;

	result = 0;
	while (*str == '\n' || *str == ' ' || *str == '\t' || *str == '\r' ||
	        *str == '\v' || *str == '\f')
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		    // if number of lines will less than 0 we'll return 0 as error
			return (0);
		str++;
	}
	while ((*str) >= '0' && (*str) <= '9')
	{
		result *= 10;
		result = result + *str - '0';
		str++;
	}
	return (result);
}

char	*str_realloc(char **str, unsigned long buff)
{
	char			*str_temp;
	unsigned int	i;

	str_temp = (char *)malloc(sizeof(char) * buff);
	i = 0;
	while (i < g_len + 1)
	{
		str_temp[i] = (*str)[i];
		i++;
	}
	free((*str));
	return (str_temp);
}

char	*str_realloc_double(char *str, unsigned long buff)
{
	char			*str_temp;
	unsigned int	i;

	str_temp = (char *)malloc(sizeof(char) * buff);
	buff >>= 1;
	i = 0;
	while (i < buff)
	{
		str_temp[i] = (str)[i];
		i++;
	}
	free(str);
	return (str_temp);
}
