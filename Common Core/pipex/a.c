/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:12:55 by pjelinek          #+#    #+#             */
/*   Updated: 2025/09/05 18:03:18 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **split)
{
	int	count;

	count = 0;
	if (split || *split)
	{
		while (split[count] != NULL)
			count++;
		ft_freeall(split, count);
	}
}

char	*create_full_path(char *dir, char *cmd)
{
	char	*tmp;
	char	*full_path;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	printf("Create Full Path tmp: %s\n", tmp);
	full_path = ft_strjoin(tmp, cmd);
	if (!full_path)
		return (free (tmp), NULL);
	printf("Create Full Path: %s\n", full_path);
	free(tmp);
	return (full_path);
}

char **find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (ft_split(&envp[i][5], ':'));
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	char	**path;
	char	*full_path;
	char	*cmd = "grep";

	path = find_path(envp);
	if (!path)
		return (0);
	int i = 0;
	while (argv[i])
		printf("%s\n", argv[i++]);
	i = 0;
	while (path[i])
		printf("%s\n", path[i++]);
	free_split(path);
	return (0);
}
