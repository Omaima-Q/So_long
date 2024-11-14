/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqaroot <oqaroot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:44:56 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2024/11/14 19:12:25 by oqaroot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	malloc_lines(char *argv, t_game *game)
{
	game->fd = open(argv, O_RDONLY);
	if (game->fd < 0)
		free_close_and_exit_error(OPEN_ERROR, game, 3);
	while (get_next_line(game->fd))
		game->lines++;
	if (game->lines == 0)
		free_close_and_exit_error(EMPTY_ERROR, game, 3);
	if (game->lines >= HEIGHT)
		free_close_and_exit_error(HEIGHT_ERROR, game, 3);
	game->map = (char **)malloc(sizeof(char *) * (game->lines + 1));
	close(game->fd);
}

void	remove_newline(char *str)
{
	size_t	len;

	len = strlen(str);
	if (len > 0 && str[len - 1] == '\n')
	{
		str[len - 1] = '\0';
	}
}

void	malloc_columns(char *argv, t_game *game)
{
	int		i;
	char	*tmp;

	i = 0;
	game->fd = open(argv, O_RDONLY);
	if (game->fd < 0)
		free_close_and_exit_error(OPEN_ERROR, game, 0);
	tmp = get_next_line(game->fd);
	remove_newline(tmp);
	game->columns = ft_strlen(tmp);
	free(tmp);
	if (game->columns >= LENGHT)
		free_close_and_exit_error(LENGHT_ERROR, game, 0);
	while (game->lines > i)
	{
		game->map[i] = (char *)malloc(sizeof(char) * (game->columns + 1));
		i++;
	}
	close(game->fd);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

void	read_map(char *argv, t_game *game)
{
	int		i;
	char	*line;

	i = 0;
	malloc_lines(argv, game);
	malloc_columns(argv, game);
	game->fd = open(argv, O_RDONLY);
	if (game->fd < 0)
		free_close_and_exit_error(OPEN_ERROR, game, 1);
	while (i < game->lines)
	{
		line = get_next_line(game->fd);
		if (line)
		{
			remove_newline(line);
			ft_memcpy(game->map[i], line, game->columns);
			game->map[i][game->columns] = '\0';
			free(line);
		}
		i++;
	}
	game->map[i] = NULL;
	// print_map(game->map);
	close(game->fd);
}
