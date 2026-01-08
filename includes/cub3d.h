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

# define ESC XK_Escape // eliminati i codici espliciti
# define W XK_w
# define S XK_s
# define A XK_a
# define D XK_d
# define LEFT XK_Left
# define RIGHT XK_Right

# define WIDTH 1920
# define HEIGHT 1280
# define MOVE 0.1
# define ROTATION 0.05
# define COLLISION 0.2

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
	int			p_counter;
	double		p_x;
	double		p_y;
	char		p_dir;
	double		ray_x;
	double		ray_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			step_x;
	int			step_y;
	double		side_x;
	double		side_y;
	double		delta_x;
	double		delta_y;
	int			hit;
	int			side;
}				t_map;

typedef struct s_img
{
	void		*img;
	// tutta l'immagine che viene pushata con mlx_put_image_to_window
	char		*addr;
	// permette di accedere ai dati che sono gia popolati in void *img
	int			bit_pp;
	int line_len; // bytes per riga
	int			endian;
	int			w;
	int			h;
}				t_img;

typedef struct s_wall
{
	int			x;
	int			start;
	int			end;
	int			line_h;
	int			tex_x;
	t_img		*tex;
}				t_wall;

typedef struct s_graphics
{
	const char	*flags[TEX_COUNT];
	char		*paths[TEX_COUNT];
	t_img		wall_img[TEX_COUNT];
	t_img		frame;
	t_img		hand_r;
	t_img		hand_l;

	int			floor[3];
	int			ceiling[3];

	int			line_len;
}				t_graphics;

typedef struct s_keys
{
	int			w;
	int			s;
	int			a;
	int			d;
	int			left;
	int			right;
}				t_keys;

typedef struct s_game
{
	t_map		*map;
	t_graphics	*graphics;
	t_keys		*keys;
	void		*mlx;
	void		*win;
}				t_game;

int				check_cub(t_game *game);
t_game			*init_game(t_game **game);
int				error_exit(char *msg, t_game *game);
void			free_map(t_map *map);
void			ft_close(char *msg, char *line, int fd, t_game *game);
int				parse_textures(char *line, t_graphics *graphics);
int				parse_rgb(char *line, t_game *game);
int				check_gstruct(t_graphics *graphics);
int				save_map(char *line, t_game *game);
int				map_line(char *line, t_game *game);
char			*clean_line(char *s);
void			free_matrix(char **matrix);
void			verify_map(t_game *game);

void			find_plane(t_map *map);
int				init_render(t_game *game);
void			init_mlx(t_game *game);
int				render_frame(t_game *game);
void			player_dir(t_game *game);
void			line_len(t_game *game);

void			init_ray(t_map *map, double camera_x);
void			dda(t_map *map);
void			draw_world(t_game *game, int i);
void			init_map_defaults(t_map *map);
void			move(t_map *map, double dx, double dy);
void			find_plane(t_map *map);
void			init_delta(t_map *map);
void			init_step(t_map *map);
void			init_side(t_map *map);
void			draw_col(t_game *game, int x, int start, int end,
					unsigned int color);
void			height_limits(int line_h, int *start, int *end);
double			distance(t_map *map);
void			put_pixel(t_img *frame, int x, int y, unsigned int color);
void			raycast(t_game *game);
unsigned int	rgb_int(int rgb[3]);
void			init_wall(t_game *game, t_wall *wall, int x, double dist);
void			moves(t_game *game);
void			rotations(t_game *game);
void			draw_hand(t_game *game, t_img *hand, int off_x, int off_y);
void			draw_texture(t_game *game, t_wall *wall);
int				exit_destroy(t_game *game);
int				check_char(char c);
void	free_all(t_game *game);

#endif
