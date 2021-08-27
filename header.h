/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 00:19:38 by lmorgana          #+#    #+#             */
/*   Updated: 2021/08/21 10:19:07 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# include <fcntl.h>

# include <string.h>
# include <errno.h>
# include "libft/libft.h"
# include "parser/parser.h"
# include "signal/signal.h"
# include <sys/stat.h>
# include "gnl/get_next_line.h"
# include <signal.h>

typedef struct s_fds
{
	char	*name_of_file;
	int		fds_file;
}			t_fds;

typedef struct s_exit_stat
{
	int			prev;
	int			curr;
}				t_exit_stat;

typedef struct s_conf
{
	t_envs	*env;
	t_exc	*args;
	t_fds	*fds;
}			t_conf;

t_exit_stat	g_exit_status;

int		rl_on_new_line(void);
void	rl_redisplay(void);
void	rl_replace_line(const char *text, int clear_undo);

char	*ft_check_for_bin(char *name_bin, t_conf *conf);
int		ft_start_all_exc(t_exc *args, t_conf *conf);
int		ft_wait_for_all_pids(t_exc *argv);
int		ft_mk_our_func(t_exc *arg, t_conf *conf);

char	*ft_is_path_exist(char *path);
int		ft_is_equal(char *str1, char *str2);
int		ft_print_error(char *str, char *code_of_error);

int		ft_our_export(t_exc *arg, t_conf *conf);
int		ft_our_unset(t_exc *arg, t_conf *conf);
int		ft_our_cd(t_exc *arg, t_conf *conf);
int		ft_our_echo(t_exc *arg, t_conf *conf);
int		ft_exc_path(t_exc *arg, t_conf *conf);

int		ft_get_pids(t_conf *conf);

int		ft_clear_exc(t_exc *args);

int		ft_sort_by_strncmp(char **env);

t_envs	*ft_create_lists_from_env(char **env);
int		ft_clear_arr(char **arr);
char	**list_into_char(t_envs *list);
int		ft_size_list(t_envs *list);
t_envs	*ft_get_by_name(char *name, t_envs *list);
int		ft_back_to_lst(char *name, char *value, t_envs **list);
int		ft_add_new_vars(char *var, t_envs *list);
int		ft_clear_env(t_envs *list);
int		ft_is_name_valid(char *name);
int		ft_print_export(char *str);
int		ft_print_env(char *buff_env);
int		ft_join_with_equal_char(char **name_value, char *str);

int		ft_increase_shlvl(char **shlvl_a);
char	*ft_my_getenv(char *name, t_envs *env);

int		ft_our_exit(t_exc *arg);

#endif
