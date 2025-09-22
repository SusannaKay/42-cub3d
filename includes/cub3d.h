#ifndef CUB3D_H
# define CUB3D_H

# include "../libraries/libft/libft.h"
# include "../libraries/mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>    // open, O_RDONLY, ecc.
# include <math.h>     // funzioni matematiche (cos, sin, sqrt, ecc.)
# include <stdio.h>    // printf, perror
# include <stdlib.h>   // malloc, free, exit
# include <string.h>   // strerror
# include <sys/time.h> // gettimeofday
# include <unistd.h>   // read, write, close, usleep

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}			t_mlx;

typedef struct s_map
{
}			t_map;

typedef struct s_game
{
	t_mlx	*mlx;
	t_map	*map;
}			t_game;

char		*ft_strcpy(char *src, char *dst);
int			check_cub(char *filename);


#endif