#include "get_next_line.h"

int	del(char *buff, char *remainder)
{
	free(buff);
	if (remainder)
		free(remainder);
	return (-1);
}

int	check_remaider(char *remainder)
{
	int	i;

	if (!remainder)
		return (0);
	i = 0;
	while (remainder[i] != '\0')
	{
		if (remainder[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	return_res(int ret)
{
	if (!ret)
		return (0);
	return (1);
}
