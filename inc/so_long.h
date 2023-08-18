/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:16:52 by jingchen          #+#    #+#             */
/*   Updated: 2023/08/14 18:06:38 by jingchen         ###   ########.fr       */
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
	ESC = 53,
	UP = 126,
	LEFT = 123,
	DOWN = 125,
	RIGHT = 124
};

typedef struct s_game
{
	char	**map;
	char	**check_map;
	int		map_width;
	int		map_height;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
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
void	read_map(char **argv, t_game *game);
void	set_element(t_game *game, int *x, int *y, char item);
void	validate_map(t_game *game);
void	put_sprites(t_game *game);
int		close_window(t_game *game);
int		event_handler(enum e_direction key, t_game *game);

#endif