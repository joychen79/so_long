/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:01:40 by jingchen          #+#    #+#             */
/*   Updated: 2023/08/18 13:18:29 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/so_long.h"

static void	put_image(t_game *game, int y, int x, char *sprite)
{
	char	*path;
	void	*img;
	int		img_width;
	int		img_height;

	path = ft_strjoin("./textures/", sprite);
	img = mlx_xpm_file_to_image(game->mlx, path, &img_width, &img_height);
	if (!img)
		exit (0);
	mlx_put_image_to_window(game->mlx, game->win, img, y * 64, x * 64);
	free(path);
}

void	put_sprites(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == '1')
				put_image(game, x, y, "Rock.xpm");
			else
				put_image(game, x, y, "Space.xpm");
			if (game->map[y][x] == 'C')
				put_image(game, x, y, "Bottle.xpm");
			else if (game->map[y][x] == 'P')
				put_image(game, x, y, "Crab.xpm");
			x++;
		}
		y++;
	}
}

static void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[game->p_y + new_y][game->p_x + new_x] != '1')
	{
		ft_printf("Moves: %d\n", ++(game->n_moves));
		put_image(game, game->p_x, game->p_y, "Space.xpm");
		put_image(game, game->p_x + new_x, game->p_y + new_y, "Space.xpm");
		put_image(game, game->p_x + new_x, game->p_y + new_y, "Crab.xpm");
		if (game->map[game->p_y + new_y][game->p_x + new_x] == 'C')
		{
			game->n_collect--;
			if (game->n_collect == 0)
			{
				set_element(game, &game->e_x, &game->e_y, 'E');
				put_image(game, game->e_x, game->e_y, "Door.xpm");
			}
		}
		game->p_x = game->p_x + new_x;
		game->p_y = game->p_y + new_y;
		if (game->map[game->p_y][game->p_x] != 'E')
			game->map[game->p_y][game->p_x] = '0';
		else if (game->n_collect == 0 && game->map[game->p_y][game->p_x] == 'E')
		{
			ft_printf("The player has reached the exit. So long!\n");
			exit(0);
		}
	}
}

int	event_handler(enum e_direction key, t_game *game)
{
	if (key == ESC)
		close_window(game);
	else if (key == W || key == UP)
		move_player(game, 0, -1);
	else if (key == A || key == LEFT)
		move_player(game, -1, 0);
	else if (key == S || key == DOWN)
		move_player(game, 0, 1);
	else if (key == D || key == RIGHT)
		move_player(game, 1, 0);
	return (0);
}
