/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqaroot <oqaroot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:04:06 by oqaroot           #+#    #+#             */
/*   Updated: 2024/11/15 20:04:07 by oqaroot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game_struct(t_game *game, char **argv)
{
	ft_memset(game, 0, sizeof(t_game));
	game->argv = argv;
}

void	init_data(t_game *game)
{
	game->lines = 0;
	game->columns = 0;
	game->player_num = 0;
	game->collect_num = 0;
	game->exit_num = 0;
	game->moves = 0;
}

void	**xpm_to_image(t_game *game, char *path)
{
	int		size;
	int		fd;
	void	**image;

	size = SIZE;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		destroy_images(game);
		mlx_clear_window(game->mlx, game->window);
		mlx_destroy_window(game->mlx, game->window);
		free_map(game->map, game);
		exit_error(IMAGE_ERROR);
	}
	close(fd);
	image = mlx_xpm_file_to_image(game->mlx, path, &size, &size);
	return (image);
}

void	init_sprites(t_game *game)
{
	game->sprite.base = xpm_to_image(game, "./assets/base1.xpm");
	game->sprite.play = xpm_to_image(game, "./assets/mario-front.xpm");
	game->sprite.wall = xpm_to_image(game, "./assets/wall.xpm");
	game->sprite.collect = xpm_to_image(game, "./assets/coins.xpm");
	game->sprite.exit = xpm_to_image(game, "./assets/peach7.xpm");
	game->sprite.left = xpm_to_image(game, "./assets/mario-left.xpm");
	game->sprite.right = xpm_to_image(game, "./assets/mario-right.xpm");
	game->sprite.up = xpm_to_image(game, "./assets/mario-back.xpm");
	game->sprite.arrow = xpm_to_image(game, "./assets/arrow.xpm");
	game->sprite.exit_sign = xpm_to_image(game, "./assets/exit_sign.xpm");
	game->sprite.start_sign = xpm_to_image(game, "./assets/start_sign.xpm");
}

void	init_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->lines > x)
	{
		y = 0;
		while (y < game->columns)
		{
			put_image(game, game->sprite.base, x, y);
			if (game->map[x][y] == PLAYER)
				put_image(game, game->sprite.play, x, y);
			else if (game->map[x][y] == WALL)
				put_image(game, game->sprite.wall, x, y);
			else if (game->map[x][y] == COLLECTIBLE)
				put_image(game, game->sprite.collect, x, y);
			else if (game->map[x][y] == EXIT)
				put_image(game, game->sprite.exit, x, y);
			y++;
		}
		x++;
	}
}
