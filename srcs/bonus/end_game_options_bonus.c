/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_options_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:46:26 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2024/11/13 15:32:03 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	end_game(t_game *game)
{
	destroy_images(game);
	mlx_clear_window(game->mlx, game->window);
	mlx_destroy_window(game->mlx, game->window);
	free_map(game->map, game);
	ft_putstr_fd("GAME ENDED\n", 1);
	exit(errno);
	return (0);
}

void	reset_game(t_game *game)
{
	destroy_images(game);
	mlx_clear_window(game->mlx, game->window);
	mlx_destroy_window(game->mlx, game->window);
	free_map(game->map, game);
	start_game(game);
}

void	put_arrows(t_game *game, int direction)
{
	int	x;
	int	y;

	x = ((SIZE * game->columns) / 2) - (SIZE / 2);
	y = ((SIZE * game->lines) / 2);
	mlx_string_put(game->mlx, game->window, x, y, 16777215, "RESTART");
	mlx_string_put(game->mlx, game->window, x, y + SIZE, 16777215, "EXIT");
	if (direction == UP)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->sprite.black, x
			- SIZE, y);
		mlx_string_put(game->mlx, game->window, x - SIZE, y, 16777215, ">");
		game->arrow_position = UP;
	}
	else if (direction == DOWN)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->sprite.black, x
			- SIZE, y - SIZE);
		mlx_string_put(game->mlx, game->window, x - SIZE, y + SIZE, 16777215,
			">");
		game->arrow_position = DOWN;
	}
}

void	select_option(t_game *game)
{
	if (game->arrow_position == UP)
		reset_game(game);
	else if (game->arrow_position == DOWN)
		end_game(game);
}

int	restart_game(int key, void *game)
{
	if (key == DOWN || key == 1)
		put_arrows(game, DOWN);
	if (key == UP || key == 13)
		put_arrows(game, UP);
	if (key == ENTER)
		select_option(game);
	return (0);
}
