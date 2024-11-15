/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqaroot <oqaroot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:59:19 by oqaroot           #+#    #+#             */
/*   Updated: 2024/11/15 19:59:34 by oqaroot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

bool	is_exit(t_game *game, int direction)
{
	if (game->map[game->x][game->y] == EXIT && game->collect_num == 0)
		close_window(game);
	else if (game->map[game->x][game->y] == EXIT)
	{
		change_location_on_map(game, direction, true);
		return (true);
	}
	return (false);
}

void	close_window(t_game *game)
{
	end_game(game);
	exit(EXIT_SUCCESS);
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
