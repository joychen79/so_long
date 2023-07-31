/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:16:52 by jingchen          #+#    #+#             */
/*   Updated: 2023/07/31 19:28:03 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "../libft/libft.h"

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
	//int		e_x;
//	int		e_y;
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
void	flood(char **map, int x, int y);
void	create_window(t_game *game);

#endif