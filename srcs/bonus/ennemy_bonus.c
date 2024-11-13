/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:49:54 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2024/11/13 16:20:57 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	game_over(t_game *game)
{
	int	x;
	int	y;

	x = ((SIZE * game->columns) / 2);
	y = ((SIZE * game->lines) / 2);
	flood_map_with_black(game);
	game->status = OVER;
	if (game->lines > 4)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->sprite.game_over,
			x, y - (2 * SIZE));
		mlx_put_image_to_window(game->mlx, game->window, game->sprite.dead, x
			- (2 * SIZE), y - (2 * SIZE));
	}
	put_arrows(game, UP);
	mlx_key_hook(game->window, restart_game, game);
}

void	move_enemy_horizontally(t_game *game, int random)
{
	if (game->map[game->enemy.x][game->enemy.y + random] == '0')
	{
		put_image(game, game->sprite.base, game->enemy.x, game->enemy.y);
		game->map[game->enemy.x][game->enemy.y] = '0';
		game->enemy.y = game->enemy.y + random;
		game->map[game->enemy.x][game->enemy.y] = 'F';
		if (random < 0)
			put_image(game, game->sprite.enemy_left, game->enemy.x,
				game->enemy.y);
		else
			put_image(game, game->sprite.enemy, game->enemy.x, game->enemy.y);
	}
	else if (game->map[game->enemy.x][game->enemy.y + random] == 'P')
		game_over(game);
}

void	move_enemy_vertically(t_game *game, int random)
{
	if (game->map[game->enemy.x + random][game->enemy.y] == '0')
	{
		put_image(game, game->sprite.base, game->enemy.x, game->enemy.y);
		game->map[game->enemy.x][game->enemy.y] = '0';
		game->enemy.x = game->enemy.x + random;
		game->map[game->enemy.x][game->enemy.y] = 'F';
		if (random < 0)
			put_image(game, game->sprite.enemy, game->enemy.x, game->enemy.y);
		else
			put_image(game, game->sprite.enemy, game->enemy.x, game->enemy.y);
	}
	else if (game->map[game->enemy.x + random][game->enemy.y] == 'P')
		game_over(game);
}

int	enemy_hook(t_game *game)
{
	int	random_direction;
	int	random_value;
	int	speed;

	game->loop++;
	random_value = (rand() % 2);
	random_direction = (rand() % 2);
	if (random_direction == 0)
		random_direction = -1;
	speed = 5555;
	game->ennemy = game->loop % speed;
	if (game->ennemy == 0 && game->status != OVER && game->status != WIN)
	{
		if (random_value == 0)
			move_enemy_horizontally(game, random_direction);
		else if (random_value == 1)
			move_enemy_vertically(game, random_direction);
	}
	return (0);
}
