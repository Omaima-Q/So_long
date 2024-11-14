/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqaroot <oqaroot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:26:59 by oqaroot           #+#    #+#             */
/*   Updated: 2024/11/14 20:27:01 by oqaroot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	put_image(t_game *game, void **image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, image, y * SIZE, x * SIZE);
}

void	put_image_direction(t_game *game, void **image, int direction)
{
	if (direction == POSITION)
		mlx_put_image_to_window(game->mlx, game->window, image, game->y * SIZE,
			game->x * SIZE);
	else if (direction == LEFT)
		mlx_put_image_to_window(game->mlx, game->window, image, (game->y + 1)
			* SIZE, game->x * SIZE);
	else if (direction == RIGHT)
		mlx_put_image_to_window(game->mlx, game->window, image, (game->y - 1)
			* SIZE, game->x * SIZE);
	else if (direction == DOWN)
		mlx_put_image_to_window(game->mlx, game->window, image, game->y * SIZE,
			(game->x - 1) * SIZE);
	else if (direction == UP)
		mlx_put_image_to_window(game->mlx, game->window, image, game->y * SIZE,
			(game->x + 1) * SIZE);
}

void	destroy_if_not_null(t_game *game, void **image)
{
	if (image)
		mlx_destroy_image(game->mlx, image);
}

void	destroy_images(t_game *game)
{
	destroy_if_not_null(game, game->sprite.base);
	destroy_if_not_null(game, game->sprite.play);
	destroy_if_not_null(game, game->sprite.wall);
	destroy_if_not_null(game, game->sprite.collect);
	destroy_if_not_null(game, game->sprite.exit);
	destroy_if_not_null(game, game->sprite.left);
	destroy_if_not_null(game, game->sprite.right);
	destroy_if_not_null(game, game->sprite.up);
	destroy_if_not_null(game, game->sprite.arrow);
	destroy_if_not_null(game, game->sprite.exit_sign);
	destroy_if_not_null(game, game->sprite.start_sign);
	destroy_if_not_null(game, game->sprite.enemy);
	destroy_if_not_null(game, game->sprite.enemy_left);
	destroy_if_not_null(game, game->sprite.enemy_up);
	destroy_if_not_null(game, game->sprite.enemy_down);
	destroy_if_not_null(game, game->sprite.game_over);
	destroy_if_not_null(game, game->sprite.dead);
}

void	flood_map_with_black(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->lines > x)
	{
		y = 0;
		while (y < game->columns)
		{
			put_image(game, game->sprite.black, x, y);
			if (game->map[x][y] == '0')
				game->map[x][y] = 'X';
			y++;
		}
		x++;
	}
}
