/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqaroot <oqaroot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:04:54 by oqaroot           #+#    #+#             */
/*   Updated: 2024/11/14 20:04:57 by oqaroot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	move_player_on_map(t_game *game, int direction)
{
	game->map[game->x][game->y] = 'P';
	if (direction == LEFT)
		game->map[game->x][game->y + 1] = '0';
	else if (direction == RIGHT)
		game->map[game->x][game->y - 1] = '0';
	else if (direction == UP)
		game->map[game->x + 1][game->y] = '0';
	else if (direction == DOWN)
		game->map[game->x - 1][game->y] = '0';
}

void	put_moves(t_game *game)
{
	char	*str;

	game->moves++;
	str = ft_itoa(game->moves);
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd("\n", 1);
	mlx_put_image_to_window(game->mlx, game->window, game->sprite.black, (2
			* (SIZE - 1)), game->lines * SIZE);
	mlx_string_put(game->mlx, game->window, (SIZE * 2), (game->lines * SIZE)
		+ (SIZE / 2) - 4, 16777215, str);
	free(str);
}

void	move(t_game *game, void **player, int direction)
{
	if (!is_wall(game, direction))
	{
		change_location_on_map(game, direction, TRUE);
		check_if_collectible(game);
		if (!is_exit(game, direction))
		{
			if (game->map[game->x][game->y] == ENEMY)
				game_over(game);
			else
			{
				put_image_direction(game, game->sprite.base, direction);
				move_player_on_map(game, direction);
				put_image_direction(game, player, POSITION);
				put_moves(game);
			}
		}
	}
}

int	deal_key(int key, t_game *game)
{
	if (key == LEFT || key == 0)
		move(game, game->sprite.left, LEFT);
	else if (key == RIGHT || key == 2)
		move(game, game->sprite.right, RIGHT);
	else if (key == DOWN || key == 1)
		move(game, game->sprite.play, DOWN);
	else if (key == UP || key == 13)
		move(game, game->sprite.up, UP);
	else if (key == ESC)
		end_game(game);
	return (0);
}
