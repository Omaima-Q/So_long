/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:47:50 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2024/11/13 17:54:31 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	is_enemy(t_game *game, int x, int y)
{
	game->enemy_num++;
	game->enemy.x = x;
	game->enemy.y = y;
}

void	is_player(t_game *game, int x, int y)
{
	game->player_num++;
	game->x = x;
	game->y = y;
}
