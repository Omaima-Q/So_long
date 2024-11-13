/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_management_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:46:43 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2024/11/13 15:51:03 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	exit_error(char *error)
{
	ft_putstr_fd("ERROR - ", 2);
	ft_putstr_fd(error, 2);
	exit(1);
}

void	free_map(char **tab, t_game *game)
{
	int	i;

	i = 0;
	while (game->lines > i)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

void	free_and_exit_error(char *error, t_game *game)
{
	free_map(game->map, game);
	exit_error(error);
}

void	free_close_and_exit_error(char *error, t_game *game, int option)
{
	if (option == 0)
	{
		free(game->map);
		game->map = NULL;
	}
	else if (option == 1)
		free_map(game->map, game);
	close(game->fd);
	exit_error(error);
}
