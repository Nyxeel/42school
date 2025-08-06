/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:16:59 by pjelinek          #+#    #+#             */
/*   Updated: 2025/08/06 10:47:53 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif


# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_data
{
	size_t	movements;
	void	*exit;
	char	**map;
	int		coin_count;
	t_coord	coins[20];
	t_coord	player;
	t_coord	enemy;
	t_coord	coin;
	t_coord	length;

}	t_data;


char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_freeall(char **freearr, size_t index);
size_t	ft_strlen(const char *str);
int		ft_strcheck(const char *str, int c);
int		find_char(char *str, int c);

#endif
