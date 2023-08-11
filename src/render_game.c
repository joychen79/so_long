/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:01:40 by jingchen          #+#    #+#             */
/*   Updated: 2023/08/11 15:22:54 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/so_long.h"

/*static void	load_image(t_game *game)
{
	int		img_width;
	int		img_height;

	img_height = 64;
	img_width = 64;
	game->player = mlx_xpm_file_to_image
		(game->mlx, "./textures/Crab.xpm", &img_width, &img_height);
	game->background = mlx_xpm_file_to_image
		(game->mlx, "./textures/Background.xpm", &img_width, &img_height);
	game->wall = mlx_xpm_file_to_image
		(game->mlx, "./textures/Wall.xpm", &img_width, &img_height);
	game->exit = mlx_xpm_file_to_image
		(game->mlx, "./textures/Exit.xpm", &img_width, &img_height);
	game->collective = mlx_xpm_file_to_image
		(game->mlx, "./textures/Bottle.xpm", &img_width, &img_height);
}

static void	set_image(t_game *game, int j, int i)
{
	if (game->map[j][i] == '1')
		mlx_put_image_to_window
			(game->mlx, game->win, game->wall, j * 64, i * 64);
	else if (game->map[j][i] == '0')
		mlx_put_image_to_window
			(game->mlx, game->win, game->background, j * 64, i * 64);
	else if (game->map[j][i] == 'C')
		mlx_put_image_to_window
			(game->mlx, game->win, game->collective, j * 64, i * 64);
	else if (game->map[j][i] == 'P')
		mlx_put_image_to_window
			(game->mlx, game->win, game->player, j * 64, i * 64);
	else if (game->map[j][i] == 'E')
		mlx_put_image_to_window
		(game->mlx, game->win, game->exit, j * 64, i * 64);
}

void	create_window(t_game *game)
{
	int		i;
	int		j;

	load_image(game);
	i = 0;
	while (i < game->map_width)
	{
		j = 0;
		while (j < game->map_height)
		{
			set_image(game, i, j);
		j++;
		}
	i++;
	}
}*/

void	put_image(t_game *game, int y, int x, char *sprite)
{
	char	*path;
	void	*img;
	int		img_width;
	int		img_height;

	path = ft_strjoin("./textures/", sprite);
	img = mlx_xpm_file_to_image(game->mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->win, img, y * 64, x * 64);
	free(path);
}

void	put_sprites(t_game *game)
{
	int		i;
	int		j;

	j = 0;
	while (j < game->map_height)
	{
		i = 0;
		while (i < game->map_width)
		{
			if (game->map[j][i] == '1')
				put_image(game, i, j, "wall.xpm");
			else
				put_image(game, i, j, "background.xpm");
			if (game->map[j][i] == 'C')
				put_image(game, i, j, "bottle.xpm");
			else if (game->map[j][i] == 'P')
				put_image(game, i, j, "crab.xpm");
			i++;
		}
		j++;
	}
}
