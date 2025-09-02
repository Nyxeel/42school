/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:26:38 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/02 11:54:08 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>

typedef struct s_fds
{
	int	input;
	int	output;
	int	curr[2];
	int	prev[2];
}	t_fds;

typedef struct s_data
{
	int cmd_count;
	char **cmds;
	char 	**path;
	t_fds	fd;
}	t_data;

int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	ft_freeall(char **freearr, size_t index);
int		find_access(char **envp, char *command);
int		open_files_bonus(int argc, char **argv, char **envp);
int		open_files(int argc, char **argv, char **envp);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
