#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "../header.h"
# define BUFFER_SIZE 100

int		get_next_line(int fd, char **line);
int		del(char *buff, char *remainder);
int		check_remaider(char *remainder);
int		return_res(int ret);
#endif