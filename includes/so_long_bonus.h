/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oqaroot <oqaroot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:37:32 by oqaroot           #+#    #+#             */
/*   Updated: 2024/11/15 20:37:35 by oqaroot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../Libft/libft.h"
# include "../Minilibx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

# define SIZE 32
# define TRUE 0
# define FALSE 1
# define OVER 1
# define WIN 2
# define LENGHT 82
# define HEIGHT 44

# define PLAYER 'P'
# define ENEMY 'N'
# define WALL '1'
# define EXIT 'E'
# define COLLECTIBLE 'C'

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
# define PATH_COLL_ERROR "Invalid map (can't to get to all the collectibles).\n"
# define LENGHT_ERROR "Invalid map (the lenght is too big for your screen).\n"
# define HEIGHT_ERROR "Invalid map (the height is too big for your screen).\n"
# define BLOCKED_ERROR "Invalid map (exit is blocking the collectibles.)\n"
# define IMAGE_ERROR "One of your sprites could not be opened.\n"
# define FOLDER_ERROR "Argument sent is not a file.\n"
# define ENEMY_ERROR "Invalid map (map should contain exactly one enemy).\n"

typedef struct enemy
{
	int			x;
	int			y;
}				t_enemy;

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
	void		**right_win;
	void		**left_win;
	void		**down_win;
	void		**up_win;
	void		**start_sign;
	void		**exit_sign;
	void		**arrow;
	void		**black;
	void		**enemy;
	void		**enemy_left;
	void		**enemy_up;
	void		**enemy_down;
	void		**game_over;
	void		**dead;
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
	int			enemy_num;
	int			moves;
	int			temp;
	int			fd;
	int			arrow_position;
	int			x;
	int			y;
	t_sprites	sprite;
	t_enemy		enemy;
	int			ennemy;
	int			loop;
	int			status;
}				t_game;

void			start_game(t_game *game);

int				end_game(t_game *game);
void			put_arrows(t_game *game, int direction);
int				restart_game(int key, void *game);

void			game_over(t_game *game);
int				enemy_hook(t_game *game);

void			exit_error(char *error);
void			free_map(char **tab, t_game *game);
void			free_and_exit_error(char *error, t_game *game);
void			free_close_and_exit_error(char *error, t_game *game,
					int option);

void			flood_fill(t_game *game);

void			init_game_struct(t_game *game, char **argv);
void			init_data(t_game *game);
void			init_sprites(t_game *game);
void			init_map(t_game *game);

void			change_location_on_map(t_game *game, int direction, int option);
bool			is_exit(t_game *game, int direction);
bool			is_wall(t_game *game, int direction);
void			check_if_collectible(t_game *game);

void			move_player_on_map(t_game *game, int direction);
void			put_moves(t_game *game);
int				deal_key(int key, t_game *game);

void			put_image(t_game *game, void **image, int x, int y);
void			put_image_direction(t_game *game, void **image, int direction);
void			destroy_images(t_game *game);
void			flood_map_with_black(t_game *game);

void			read_map(char *argv, t_game *game);

void			is_enemy(t_game *game, int x, int y);
void			is_player(t_game *game, int x, int y);

void			validate_map(char *argv, t_game *game);
void			print_map(char **map);
void			remove_newline(char *str);

#endif