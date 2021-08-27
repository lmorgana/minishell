/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlizzie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:10:00 by mlizzie           #+#    #+#             */
/*   Updated: 2021/08/21 10:19:07 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# include "../libft/libft.h"

typedef struct s_exc
{
	char	*name;
	int		checkComnd;
	char	*path_bin;
	char	**flags;
	int		pipe_stat[2];
	int		pipe[2];
	int		inFd;
	int		outFd;
	int		type;
	int		ch_pid;
	char	*stopWord;
}			t_exc;

typedef struct s_envs
{
	char			*name;
	char			*value;
	struct s_envs	*next;
}				t_envs;

typedef struct s_token
{
	char			*str;
	int				redOrPipe;
	struct s_token	*next;
}				t_token;

char	*preparser(char *line);
char	*outputError(char *str, char *line, int exit_status);
void	createToken(t_token **token, char *str, int redOrPipe);
char	*replacementKeyEnv(char *line, t_envs *env);
int		elementInQuote(char *line, int i, int quoteD);
char	*parsQuote(char *line, int *i, char quote);
t_token	*checkPipeAfterRed(t_token *token);
void	*free_token(t_token **top);
t_exc	*convertTokenInExc(t_token *token);
int		countToken(t_token *token);
void	*free_exc(t_exc *exc, int size);
char	**initFlags(char **flags, int size);
int		ft_double_Red(t_token *token);
int		inQuoteS(char *line, int i);
t_exc	*initArray(int size, t_exc *exc);
int		getTypeComand(char *str);
t_token	*writeRedInExc(t_exc *exc, int i, t_token *token);
int		getNumRed(t_token *token);
void	getKeyEnv(t_token *token, t_envs *env);
t_token	*checkToken(t_token *token, char *line);
t_token	*parser(char *line, t_envs *env);
t_exc	*convertTokenInExc(t_token *token);
void	clear_memory(t_token **token, t_exc *exc);
void	ctrl_for_redirec(int sig);
#endif
