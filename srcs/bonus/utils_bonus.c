/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:47:50 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2024/11/12 16:47:52 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

/*If the character found in the map is a fox, the position is saved and the 
number of foxes is updated in the game struct.*/
void	is_fox(t_game *game, int x, int y)
{
	game->fox_num++;
	game->fox.x = x;
	game->fox.y = y;
}

/*If the character found in the map is a player, the position is saved and the 
number of players is updated in the game struct.*/
void	is_player(t_game *game, int x, int y)
{
	game->player_num++;
	game->x = x;
	game->y = y;
}
