/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:15:01 by jingchen          #+#    #+#             */
/*   Updated: 2023/08/11 15:01:42 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/so_long.h"

# include <fcntl.h>

int main (int ac, char **av)
{
	t_game	*game;

	game = NULL;
	if (ac != 2)
		print_errors("Expected More Information!");
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		exit(1);
	else
		read_map(av, game);
	game->mlx = mlx_init();
	game->win = mlx_new_window
		(game->mlx, game->map_width * 64, game->map_height * 64, "so_long");
	put_sprites(game);
	mlx_loop(game->mlx);
}



