/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhegewal <linus.hegewald8@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:58:03 by lhegewal          #+#    #+#             */
/*   Updated: 2025/02/23 11:17:47 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	ft_error(int c);

char	*ft_strstr(char *dict, char *num)
{
	int	i;
	int	j;

	if (!dict || !num)
		return (0);
	if (num[0] == '\0')
	{
		return (0);
	}
	i = 0;
	while (dict[i])
	{
		j = 0;
		while (dict[i + j] == num[j] && num[j])
		{
			j++;
			if (num[j] == '\0' && dict[i + j] != '0')
			{
				return (&dict[i]);
			}
		}
		i++;
	}
	return (0);
}

char	*ft_get_space(char *dict)
{
	int		j;
	char	*word;

	j = 0;
	while (dict[j] != '\0')
		j++;
	word = (char *)malloc(sizeof(char) * (j + 2));
	if (!word)
	{
		ft_error(1);
		return (0);
	}
	return (word);
}

char	*ft_get_word(char *dict)
{
	int		i;
	int		j;
	char	*word;

	i = 0;
	j = 0;
	while (dict[i] != ':')
		i++;
	i++;
	while (dict[i] == 32 || (dict[i] >= 9 && dict[i] <= 13))
		i++;
	word = ft_get_space(&dict[i]);
	j = 0;
	while (dict[i] != '\n')
	{
		word[j] = dict[i];
		i++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

char	*ft_get_num(char *dict, char *num)
{
	char	*dict_num;
	char	*word;

	dict_num = ft_strstr(dict, num);
	if (!dict_num)
	{
		ft_error(2);
		word = (char *)malloc(sizeof(char) * 2);
		word[0] = 0;
		return (word);
	}
	word = ft_get_word(dict_num);
	if (!word)
	{
		ft_error(2);
		return (NULL);
	}
	return (word);
}
