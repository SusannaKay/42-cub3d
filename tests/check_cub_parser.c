#include "../includes/cub3d.h"
#include <stdio.h>

static void	free_graphics_paths(t_graphics *graphics)
{
	int	i;

	if (!graphics)
		return ;
	i = 0;
	while (i < TEX_COUNT)
	{
		if (graphics->paths[i])
		{
			free(graphics->paths[i]);
			graphics->paths[i] = NULL;
		}
		i++;
	}
	free(graphics);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->map)
	{
		i = 0;
		while (map->map[i])
		{
			free(map->map[i]);
			map->map[i] = NULL;
			i++;
		}
		free(map->map);
		map->map = NULL;
	}
	if (map->filename)
	{
		free(map->filename);
		map->filename = NULL;
	}
	free(map);
}

void	free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	free(matrix);
}

static void	cleanup_game(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		free_map(game->map);
	if (game->graphics)
		free_graphics_paths(game->graphics);
	free(game);
}

void	error_exit(char *msg, t_game *game)
{
	if (msg)
		fprintf(stderr, "Error:\n%s\n", msg);
	cleanup_game(game);
	exit(EXIT_FAILURE);
}

static void	init_graphics_for_test(t_graphics *graphics)
{
	if (!graphics)
		return ;
	graphics->flags[TEX_NO] = "NO";
	graphics->flags[TEX_SO] = "SO";
	graphics->flags[TEX_WE] = "WE";
	graphics->flags[TEX_EA] = "EA";
	graphics->floor[0] = -1;
	graphics->floor[1] = -1;
	graphics->floor[2] = -1;
	graphics->ceiling[0] = -1;
	graphics->ceiling[1] = -1;
	graphics->ceiling[2] = -1;
}

static t_game	*prepare_game(const char *path)
{
	t_game	*game;

	if (!path)
		return (NULL);
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = ft_calloc(1, sizeof(t_map));
	if (!game->map)
		return (cleanup_game(game), NULL);
	game->graphics = ft_calloc(1, sizeof(t_graphics));
	if (!game->graphics)
		return (cleanup_game(game), NULL);
	game->map->filename = ft_strdup(path);
	if (!game->map->filename)
		return (cleanup_game(game), NULL);
	init_graphics_for_test(game->graphics);
	return (game);
}

static void	print_parsing_result(t_game *game)
{
	int	i;

	printf("Textures:\n");
	i = 0;
	while (i < TEX_COUNT)
	{
		printf("  %s -> %s\n",
			game->graphics->flags[i],
			game->graphics->paths[i] ? game->graphics->paths[i] : "(null)");
		i++;
	}
	printf("\nMap:\n");
	if (!game->map->map)
	{
		printf("  (empty)\n");
		return ;
	}
	i = 0;
	while (game->map->map[i])
	{
		printf("  %s", game->map->map[i]);
		if (game->map->map[i][0] && game->map->map[i][ft_strlen(game->map->map[i]) - 1] != '\n')
			printf("\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	const char	*path;
	t_game		*game;

	path = (argc > 1) ? argv[1] : "maps/map.cub";
	game = prepare_game(path);
	if (!game)
		return (fprintf(stderr, "Unable to allocate game structures\n"), 1);
	if (check_cub(game) == 0)
	{
		printf("Parsing succeeded for %s\n\n", path);
		print_parsing_result(game);
		cleanup_game(game);
		return (0);
	}
	fprintf(stderr, "Parsing failed for %s\n", path);
	cleanup_game(game);
	return (1);
}
