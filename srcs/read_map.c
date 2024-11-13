/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:44:56 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2024/11/12 21:58:46 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Calculates the number of lines and mallocs that amount of strings to the 
game->map table.*/
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
	// printf("line count = %d\n", game->lines);
	game->map = (char**)malloc(sizeof(char*) * (game->lines + 1));
	close(game->fd);
}
void	remove_newline(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';  // Replace the newline character with a null terminator
    }
}

/*Calculates the number of columns and if it is less/equal to 128,
mallocs that amount of characters in each game->map string.*/
void	malloc_columns(char *argv, t_game *game)
{
	int		i;
	char*	tmp;
	
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
	printf("column = %d\n", game->columns);
	while (game->lines > i)
	{
		game->map[i] = ft_calloc(game->columns + 1, sizeof(char));  // Correct allocation for a string
		i++;
	}
	close(game->fd);
}

/*Mallocs the lines and the columns of the game->map variable, then uses 
get_next_line to read the map file and copies it's content to game->map.*/
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
		line = get_next_line(game->fd);  // Get the next line
		if (line)  // Check if line is not NULL
		{
			remove_newline(line);  // Remove the newline character from the line
			ft_memcpy(game->map[i], line, game->columns);  // Copy the line to the map
			game->map[i][game->columns] = '\0';  // Ensure null-termination
			free(line);  // Don't forget to free the line after using it
		}
		i++;
	}
	printf("i = %d\n", i);
	game->map[i] = NULL;	
	print_map(game->map);
	close(game->fd);
}


