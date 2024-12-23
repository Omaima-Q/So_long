/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqaroot <oqaroot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:03:31 by oqaroot           #+#    #+#             */
/*   Updated: 2024/11/15 20:03:33 by oqaroot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	validate_characters(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->lines > x)
	{
		y = 0;
		while (game->columns > y)
		{
			if (game->map[x][y] == PLAYER)
			{
				game->player_num++;
				game->x = x;
				game->y = y;
			}
			else if (game->map[x][y] == COLLECTIBLE)
				game->collect_num++;
			else if (game->map[x][y] == EXIT)
				game->exit_num++;
			else if (game->map[x][y] != WALL && game->map[x][y] != '0')
				free_and_exit_error(CHAR_ERROR, game);
			y++;
		}
		x++;
	}
}

void	validate_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->columns)
	{
		if (game->map[0][i] != WALL || game->map[game->lines - 1][i] != WALL)
			free_and_exit_error(WALL_ERROR, game);
		if (i < game->lines && (game->map[i][game->columns - 1] != WALL
			|| game->map[i][0] != WALL))
			free_and_exit_error(WALL_ERROR, game);
		i++;
	}
}

void	check_if_rectangle(t_game *game)
{
	int	i;

	i = 0;
	while (game->lines > i)
	{
		if (ft_strlen(game->map[i]) != (size_t)game->columns)
			free_and_exit_error(RECTANGLE_ERROR, game);
		i++;
	}
}

void	validate_extension(char *argv)
{
	int		i;
	int		fd;
	void	*buf;

	i = (ft_strlen(argv) - 4);
	if (ft_strncmp(".ber", &argv[i], 4) != 0)
		exit_error(EXTENSION_ERROR);
	fd = open(argv, O_RDONLY);
	if (read(fd, &buf, 1) == -1)
	{
		close(fd);
		exit_error(FOLDER_ERROR);
	}
	close(fd);
}

void	validate_map(char *argv, t_game *game)
{
	validate_extension(argv);
	read_map(argv, game);
	check_if_rectangle(game);
	validate_walls(game);
	validate_characters(game);
	if (game->player_num != 1)
		free_and_exit_error(PLAY_ERROR, game);
	if (game->collect_num < 1)
		free_and_exit_error(COLL_ERROR, game);
	if (game->exit_num != 1)
		free_and_exit_error(EXIT_ERROR, game);
	flood_fill(game);
}
