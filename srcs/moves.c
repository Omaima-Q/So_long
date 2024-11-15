/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqaroot <oqaroot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:59:43 by oqaroot           #+#    #+#             */
/*   Updated: 2024/11/15 19:59:46 by oqaroot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_moves(t_game *game)
{
	game->moves++;
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd("\n", 1);
}

void	move(t_game *game, void **player, int direction)
{
	if (!is_wall(game, direction))
	{
		change_location_on_map(game, direction, TRUE);
		check_if_collectible(game);
		if (!is_exit(game, direction))
		{
			put_image_direction(game, game->sprite.base, direction);
			put_image_direction(game, player, POSITION);
			put_moves(game);
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
