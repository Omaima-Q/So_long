/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqaroot <oqaroot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:44:05 by oqaroot           #+#    #+#             */
/*   Updated: 2024/11/15 20:12:10 by oqaroot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	start_game(t_game *game)
{
	init_data(game);
	validate_map(game->argv[1], game);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, (SIZE * game->columns), (SIZE
				* game->lines) + (SIZE / 2), "Mario & Princess Peach");
	init_sprites(game);
	init_map(game);
	mlx_string_put(game->mlx, game->window, 8, (game->lines * SIZE) + (SIZE / 2)
		- 4, 16777215, "Moves:");
	mlx_hook(game->window, 17, 0, end_game, game);
	mlx_hook(game->window, 1, 0, deal_key, game);
	mlx_loop_hook(game->mlx, enemy_hook, game);
	mlx_key_hook(game->window, deal_key, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_error(ARG_ERROR);
	init_game_struct(&game, argv);
	ft_memset(&game, 0, sizeof(t_game));
	game.argv = argv;
	start_game(&game);
	return (0);
}
