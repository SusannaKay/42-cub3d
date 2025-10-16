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

typedef enum e_tex
{
	TEX_NO = 0,
	TEX_SO = 1,
	TEX_WE = 2,
	TEX_EA = 3,
	TEX_COUNT = 4,
}				t_tex;

typedef struct s_map
{
	char		**map;
	char		*filename;
	int			in_map;
	int			height;
	int			width;
}				t_map;

typedef struct s_graphics
{
	const char	*flags[TEX_COUNT];
	char		*paths[TEX_COUNT];
	void		*wall_img[TEX_COUNT];
	int			floor[3];
	int			ceiling[3];
}				t_graphics;

typedef struct s_player
{
	int			p_x;
	int			p_y;
	char		p_dir;
}				t_player;

typedef struct s_game
{
	t_map		*map;
	t_graphics	*graphics;
	t_player	*player;
	void		*mlx;
	void		*win;
}				t_game;

int				check_cub(t_game *game);
void			init_graphics_defaults(t_graphics *graphics);
void			init_map_defaults(t_map *map);
t_game			*init_game(t_game *game);
void			error_exit(char *msg, t_game *game);
void			free_map(t_map *map);
char			*check_line(char *line);
void			ft_close(char *msg, char *line, int fd, t_game *game);
int				parse_textures(char *line, t_graphics *graphics);
int				parse_rgb(char *line, t_game *game);
int				check_gstruct(t_graphics *graphics);
int				save_map(char *line, t_game *game);
int				map_line(char *line, t_game *game);
char			*clean_line(char *s);
void	free_matrix(char **matrix);
#endif
