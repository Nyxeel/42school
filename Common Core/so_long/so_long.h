/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjelinek <pjelinek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:16:59 by pjelinek          #+#    #+#             */
/*   Updated: 2025/08/06 20:24:35 by pjelinek         ###   ########.fr       */
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
# include <mlx.h>

# define ESC 65307
# define W 1731
# define A 1734
# define S 1753
# define D 1751
# define STOP 0
# define LEFT 1
# define RIGHT 2
# define UP 3
# define DOWN 4

typedef struct s_mlx
{
	void	*connect;
	void	*win;
	void	*img;
	int		width;
	int		height;
}	t_mlx;


typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_data
{
	size_t	movements;
	//void	*exit;
	char	**map;
	int		coin_count;
	bool	fill;
	t_coord	coins[20];
	t_coord	player;
	t_coord	boss;
	t_coord	exit;
	t_coord	length;

}	t_data;

typedef struct s_bool
{
	bool	player;
	bool	boss;
	bool	coins;
	bool	exit;

}	t_bool;





char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_freeall(char **freearr, size_t index);
size_t	ft_strlen(const char *str);
int		ft_strcheck(const char *str, int c);
int		find_char(char *str, int c);
void	*ft_bzero(void *s, size_t n);
int		find_doubles(char *str, int c);

#endif
