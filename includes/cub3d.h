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

typedef struct s_map
{
	char		**map;
	char		*filename;
	int			in_map;
	int			p_x;
	int			p_y;
	char		p_orient;
}				t_map;

typedef struct s_graphics
{
	void		*no;
	void		*so;
	void		*we;
	void		*ea;
	int			*floor;
	int			*ceiling;
}				t_graphics;

typedef struct s_game
{
	t_map		*map;
	t_graphics	*graphics;
	void		*mlx;
	void		*win;
}				t_game;

int				check_cub(char *filename);
t_game			*init_game(t_game *game);
void			error_exit(char *msg, t_game *game);
void	free_map(t_map *map);

#endif