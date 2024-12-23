/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqaroot <oqaroot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:05:13 by oqaroot           #+#    #+#             */
/*   Updated: 2024/11/15 19:40:34 by oqaroot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	change_location_on_map(t_game *game, int direction, int option)
{
	if ((direction == LEFT && option == TRUE) || (direction == RIGHT
			&& option == FALSE))
		game->y--;
	else if ((direction == RIGHT && option == TRUE) || (direction == LEFT
			&& option == FALSE))
		game->y++;
	else if ((direction == DOWN && option == TRUE) || (direction == UP
			&& option == FALSE))
		game->x++;
	else if ((direction == UP && option == TRUE) || (direction == DOWN
			&& option == FALSE))
		game->x--;
}

void	is_win(t_game *game, void **player, void **exit, int direction)
{
	flood_map_with_black(game);
	game->status = WIN;
	put_image_direction(game, exit, POSITION);
	put_image_direction(game, player, direction);
	put_moves(game);
	ft_putstr_fd("\nYOU WON!!\n", 1);
	put_arrows(game, UP);
	mlx_key_hook(game->window, restart_game, game);
}

bool	is_exit(t_game *game, int direction)
{
	if (game->map[game->x][game->y] == EXIT)
	{
		if (game->collect_num == 0)
		{
			if (direction == LEFT)
				is_win(game, game->sprite.left, game->sprite.right_win, LEFT);
			if (direction == RIGHT)
				is_win(game, game->sprite.right, game->sprite.left_win, RIGHT);
			if (direction == DOWN)
				is_win(game, game->sprite.play, game->sprite.up_win, DOWN);
			if (direction == UP)
				is_win(game, game->sprite.up, game->sprite.down_win, UP);
		}
		change_location_on_map(game, direction, FALSE);
		return (true);
	}
	return (false);
}

bool	is_wall(t_game *game, int direction)
{
	if ((direction == LEFT && (game->map[game->x][game->y - 1] != WALL))
		|| (direction == RIGHT && (game->map[game->x][game->y + 1] != WALL))
		|| (direction == DOWN && (game->map[game->x + 1][game->y] != WALL))
		|| (direction == UP && (game->map[game->x - 1][game->y] != WALL)))
		return (false);
	return (true);
}

void	check_if_collectible(t_game *game)
{
	if (game->map[game->x][game->y] == COLLECTIBLE)
	{
		game->map[game->x][game->y] = 0;
		game->collect_num--;
		put_image_direction(game, game->sprite.base, POSITION);
	}
}
