/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:16:52 by jingchen          #+#    #+#             */
/*   Updated: 2023/08/11 19:08:45 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "../libft/libft.h"
# include <fcntl.h>

enum e_direction
{
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	ESC = 53
};

typedef struct s_game
{
	char	**map;
	char	**check_map;
	int		map_width;
	int		map_height;
	int		p_x;
	int		p_y;
	int		n_moves;
	int		n_collect;
	void	*mlx;
	void	*win;
	void	*player;
	void	*wall;
	void	*background;
	void	*collective;
	void	*exit;
	int		img_width;
	int		img_height;
}	t_game;

void	print_errors(char *errors);
//void	flood(char **map, int x, int y);
//int		check_walls(t_game *game);
//int		check_element(t_game *game, char c);
//int		check_accesible(t_game *game);
//char	*get_map(t_game *game, int fd);
void	read_map(char **argv, t_game *game);
void	set_player(t_game *game, int *x, int *y, char item);
//void	create_window(t_game *game);
void	validate_map(t_game *game);
//void	put_image(t_game *game, int y, int x, char *sprite);
void	put_sprites(t_game *game);
int		close_window(t_game *game);
int		event_handler(enum e_direction key, t_game *game);
//void	move_player(t_game *game, int new_x, int new_y);

#endif