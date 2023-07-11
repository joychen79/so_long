/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:16:52 by jingchen          #+#    #+#             */
/*   Updated: 2023/07/11 20:10:03 by jingchen         ###   ########.fr       */
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
	void	*mlx;
	void	*win;
	char	**map;
	//char	**check_map;
	int		map_width;
	int		map_height;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		n_moves;
	int		n_collect;
}	t_game;

void	print_errors(char *errors);

#endif