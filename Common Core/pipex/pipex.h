/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:26:38 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/03 15:43:27 by pjelinek         ###   ########.fr       */
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
	int				cmd_count;
	char			**cmds;
	char			**path;
	char			**access_path;
	char			**cmd_split;
	int				status;
	t_fds			fd;
}	t_data;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	ft_freeall(char **freearr, size_t index);
int		find_access(t_data *pipex, char *command);
int		open_files_bonus(int argc, char **argv, char **envp);
void	*ft_calloc(size_t nmemb, size_t size);
void	cleanup(t_data *pipex, char *message, int exit_id);
size_t	ft_strlen(const char *str);
int		pipe_fork(t_data *pipex);

/* ##################FULL VALGRIND CHECK
valgrind --leak-check=full --show-leak-kinds=all
--track-origins=yes -trace-children=yes --trace-children-skip=/usr/bin/cat
./pipex infile "grep 2" "cat" outfile

##### CHECK GREP COMMAND
valgrind --leak-check=full /usr/bin/grep 2 infile
*/
#endif
