/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:12:55 by pjelinek          #+#    #+#             */
/*   Updated: 2025/07/25 11:47:46 by pjelinek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* void	run_pipex(char **av)
{
	__ENVIROMENT
}


int	main(int ac, char **av)
{
	if (ac == 4)
		run_pipex(av);
	else
		return (1);
	return (0);

}*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && str1[i] && str2[i] && i < n - 1)
		i++;
	return (str1[i] - str2[i]);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	char	**arr;

	i = 0;
	(void)argc;
	(void)argv;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			arr = ft_split(&envp[i][5], ':');
			i = 0;
			while (arr[i])
			{
				printf("%s\n", arr[i]);
				i++;
			}
		}
		i++;
	}
	return (0);
}

//(void)(dup2(fd[1], 1) >= 0 && dup2(fd[1], 2) >= 0);
