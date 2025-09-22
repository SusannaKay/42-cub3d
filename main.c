#include "./includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_mlx *mlx;
	(void)argv;


	if (argc == 2)
	{
		mlx = malloc(sizeof(t_mlx));
		if (!mlx)
			return(1);
		mlx->mlx = mlx_init();
		mlx->win = mlx_new_window(mlx->mlx, 100, 100, "Cub3d");
		mlx_loop(mlx->mlx);
		return (0);
	}
	ft_printf("Error:\n you need a map .cub to play the game");
}