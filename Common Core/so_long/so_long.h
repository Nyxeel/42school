/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:16:59 by pjelinek          #+#    #+#             */
/*   Updated: 2025/08/08 10:46:10 by netrunner        ###   ########.fr       */
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
# include "mlx.h"

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363
# define TILE_SIZE 64
# define ON_DESTROY 17
# define STOP 0


typedef struct s_sprite
{
	void	*down;
	void	*left;
	void	*up;
	void	*right;
	char	*path;
}	t_sprite;


typedef struct s_mlx
{
	void		*connect;
	void		*win;
	void		*wall_img;
	int			width;
	int			height;
	void		*player_img;
	void		*coin_img;
	t_sprite	boss;
}	t_mlx;


typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_data
{
	size_t	move_count;
	int		coin_count;
	char	**map;
	t_coord	length;
	t_coord	player;
	t_coord	coins;
	t_coord	boss;
	t_coord	exit;
	t_mlx 	mlx;
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
int		mlx_initialize(char *map_path, t_data *game);
int		count_lines(char **split);
char	**extract_map(char *map_path);
void	exit_call(char *message, char **split, t_data *game);
void	create_map(t_data *game);
void	update_game(t_data *game, char id);
void 	exit_mlx(t_data *game, char *message);


#endif
