/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqaroot <oqaroot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:03:39 by oqaroot           #+#    #+#             */
/*   Updated: 2024/11/15 20:03:41 by oqaroot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	mlx_hook(game->window, 2, 0, deal_key, game);
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
