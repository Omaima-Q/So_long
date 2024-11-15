/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqaroot <oqaroot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:44:11 by oqaroot           #+#    #+#             */
/*   Updated: 2024/11/14 20:44:13 by oqaroot          ###   ########.fr       */
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
