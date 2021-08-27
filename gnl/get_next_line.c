#include "get_next_line.h"

char	*write_remaider(char *remainder, char *buff)
{
	int		size_buff;
	int		size_remainder;
	char	*new_remainder;

	size_buff = ft_strlen(buff);
	size_remainder = ft_strlen(remainder);
	new_remainder = malloc(sizeof(char) * (size_buff + size_remainder + 1));
	if (!(new_remainder))
		return (NULL);
	new_remainder[size_buff + size_remainder] = '\0';
	size_remainder = 0;
	if (remainder)
	{
		while (remainder[size_remainder] != '\0')
		{
			new_remainder[size_remainder] = remainder[size_remainder];
			size_remainder++;
		}
		free(remainder);
	}
	size_buff = 0;
	while (buff[size_buff] != '\0')
		new_remainder[size_remainder++] = buff[size_buff++];
	return (new_remainder);
}

char	*get_line(char *remainder)
{
	int		size;
	char	*line;

	if (!remainder)
		return (NULL);
	size = 0;
	while (remainder[size] != '\n' && remainder[size] != '\0')
		size++;
	line = malloc(sizeof(*line) * (size + 1));
	if (!(line))
		return (NULL);
	line[size] = '\0';
	size--;
	while (size >= 0)
	{
		line[size] = remainder[size];
		size--;
	}
	return (line);
}

char	*fill_remainder(char **remainder, char **new_remainder, int *size)
{
	 int	size_new;

	(*size)++;
	size_new = 0;
	while ((*remainder)[*size] != '\0')
	{
		(*new_remainder)[size_new] = (*remainder)[*size];
		(*size)++;
		size_new++;
	}
	(*new_remainder)[size_new] = '\0';
	free ((*remainder));
	return (*new_remainder);
}

char	*get_new_remainder(char *remainder)
{
	int		size;
	int		size_new;
	char	*new_remainder;

	size = 0;
	while (remainder[size] != '\n' && remainder[size] != '\0')
		size++;
	if (remainder[size] == '\n')
	{
		if (size)
			size_new = sizeof(char) * (ft_strlen(remainder) - size + 1);
		else
			size_new = sizeof(*new_remainder) * (ft_strlen(remainder) - size);
		new_remainder = malloc(size_new);
		if (!(new_remainder))
		{
			free (remainder);
			return ((char *) - 1);
		}
		new_remainder = fill_remainder(&remainder, &new_remainder, &size);
		return (new_remainder);
	}
	else
		free (remainder);
	return (remainder = NULL);
}

int	get_next_line(int fd, char **line)
{
	static char	*remainder;
	int			ret;
	char		*buff;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || remainder == (char *) - 1)
		return (-1);
	buff = malloc(sizeof(*buff) * (BUFFER_SIZE + 1));
	if (!(buff))
		return (-1);
	ret = 1;
	while (!(check_remaider(remainder)) && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
			return (del(buff, remainder));
		buff[ret] = '\0';
		remainder = write_remaider(remainder, buff);
	}
	*line = get_line(remainder);
	if (*line == NULL)
		return (-1);
	remainder = get_new_remainder(remainder);
	free(buff);
	return (return_res(ret));
}
