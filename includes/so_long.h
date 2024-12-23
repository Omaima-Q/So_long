/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqaroot <oqaroot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:44:25 by oqaroot           #+#    #+#             */
/*   Updated: 2024/11/15 20:33:49 by oqaroot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include "../Minilibx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

# define SIZE 32
# define TRUE 0
# define FALSE 1
# define LENGHT 82
# define HEIGHT 44

/*MAP*/
# define PLAYER 'P'
# define WALL '1'
# define EXIT 'E'
# define COLLECTIBLE 'C'

/*KEYS*/
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define ESC 53
# define ENTER 36
# define POSITION 0

# define ARG_ERROR "Number of arguments is invalid.\n"
# define OPEN_ERROR "Invalid map (file could not be opened).\n"
# define EMPTY_ERROR "Invalid map (map is empty).\n"
# define EXIT_ERROR "Invalid map (map should contain exactly one exit).\n"
# define COLL_ERROR "Invalid map (should contain at least one collectible).\n"
# define PLAY_ERROR "Invalid map (map should contain exactly one player).\n"
# define EXTENSION_ERROR "Invalid map (extension should be .ber).\n"
# define RECTANGLE_ERROR "Invalid map (map should form a rectangle).\n"
# define WALL_ERROR "Invalid map (map should be surrounded by walls).\n"
# define CHAR_ERROR "Invalid map (invalid character found).\n"
# define PATH_EXIT_ERROR "Invalid map (impossible to get to the exit).\n"
# define PATH_COLL_ERROR "Invalid map (can't get to all the collectibles).\n"
# define LENGHT_ERROR "Invalid map (the lenght is too big for your screen).\n"
# define HEIGHT_ERROR "Invalid map (the height is too big for your screen).\n"
# define BLOCKED_ERROR "Invalid map (exit is blocking the collectibles.)\n"
# define IMAGE_ERROR "One of your sprites could not be opened.\n"
# define FOLDER_ERROR "Argument sent is not a file.\n"

typedef struct sprites
{
	void		**base;
	void		**play;
	void		**wall;
	void		**collect;
	void		**exit;
	void		**left;
	void		**right;
	void		**up;
	void		**exit_sign;
	void		**start_sign;
	void		**arrow;
}				t_sprites;

typedef struct game
{
	char		**argv;
	char		**map;
	void		*window;
	void		*mlx;
	int			lines;
	int			columns;
	int			player_num;
	int			collect_num;
	int			exit_num;
	int			moves;
	int			temp;
	int			fd;
	int			arrow_position;
	int			x;
	int			y;
	t_sprites	sprite;
}				t_game;

/*main*/
void			start_game(t_game *game);

/*end_game_options*/
int				end_game(t_game *game);
void			put_arrows(t_game *game, int direction);
int				restart_game(int key, void *game);

/*exit_management*/
void			exit_error(char *error);
void			free_map(char **tab, t_game *game);
void			free_and_exit_error(char *error, t_game *game);
void			free_close_and_exit_error(char *error, t_game *game,
					int option);

/*flood_fill*/
void			flood_fill(t_game *game);

/*init*/
void			init_game_struct(t_game *game, char **argv);
void			init_data(t_game *game);
void			init_sprites(t_game *game);
void			init_map(t_game *game);

/*moves_utils*/
void			change_location_on_map(t_game *game, int direction, int option);
bool			is_exit(t_game *game, int direction);
bool			is_wall(t_game *game, int direction);
void			check_if_collectible(t_game *game);

/*moves*/
void			put_moves(t_game *game);
int				deal_key(int key, t_game *game);

/*put_images*/
void			put_image(t_game *game, void **image, int x, int y);
void			put_image_direction(t_game *game, void **image, int direction);
void			destroy_images(t_game *game);

/*read_map*/
void			read_map(char *argv, t_game *game);

/*validate_map*/
void			validate_map(char *argv, t_game *game);

void			print_map(char **map);
// At the top of moves_utils.c
void			close_window(t_game *game);

#endif