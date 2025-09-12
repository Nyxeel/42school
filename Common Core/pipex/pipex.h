/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:26:38 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/12 14:38:26 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define ISDIR 13

# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_fds
{
	int	input;
	int	output;
	int	curr[2];
	int	prev[2];
}	t_fds;

typedef struct s_data
{
	int		cmd_count;
	char	**cmds;
	char	**path;
	char	**access_path;
	char	**cmd_split;
	int		status;
	t_fds	fd;
}	t_data;

/* ========= libft Utilities ========= */
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(const char *s1, const char *s2);
char	**ft_split(const char *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);

/* =	==== Speicher- und Array-Helfer ========= */
void	free_split(char **split);
void	ft_freeall(char **freearr, size_t index);

/* =	==== Pipex-Kern-API ========= */
void	find_access(t_data *pipex, char *command);
void	pipe_fork(t_data *pipex);
void	cleanup(t_data *pipex, char *message, int exit_code);
void	free_split_exit(int exit_code, char *message, t_data *pipex);
void	handle_errno(t_data *pipex, int error_code);

/* ##################FULL VALGRIND CHECK
valgrind --leak-check=full --show-leak-kinds=all
--track-origins=yes -trace-children=yes --trace-children-skip=/usr/bin/cat
./pipex infile "grep 2" "cat" outfile

##### CHECK GREP COMMAND
valgrind --leak-check=full /usr/bin/grep 2 infile
*/
#endif
