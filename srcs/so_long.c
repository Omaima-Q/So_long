/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:44:47 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2024/11/12 16:44:48 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Initiates all of the necessary t_game struct data and saves the map after
validating it. Then, initiates a new mlx window with the map and sprites
and starts the game loop.*/
void	start_game(t_game *game)
{
	init_data(game);
	validate_map(game->argv[1], game);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, (SIZE * game->columns), (SIZE
				* game->lines), "Mario & Princess Peach");
	init_sprites(game);
	init_map(game);
	mlx_hook(game->window, 17, 0, end_game, game);
	mlx_key_hook(game->window, deal_key, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_error(ARG_ERROR);
	init_game_struct(&game, argv);
	start_game(&game);
	return (0);
}
