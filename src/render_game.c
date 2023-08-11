/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:01:40 by jingchen          #+#    #+#             */
/*   Updated: 2023/08/11 19:13:33 by jingchen         ###   ########.fr       */
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
		(game->mlx, "./textures/Mermaid.xpm", &img_width, &img_height);
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
			(game->mlx, game->win, game->wall, i * 64, j * 64);
	else if (game->map[j][i] == '0')
		mlx_put_image_to_window
			(game->mlx, game->win, game->background, i * 64, j * 64);
	else if (game->map[j][i] == 'C')
		mlx_put_image_to_window
			(game->mlx, game->win, game->collective, i * 64, j * 64);
	else if (game->map[j][i] == 'P')
		mlx_put_image_to_window
			(game->mlx, game->win, game->player, i * 64, j * 64);
	else if (game->map[j][i] == 'E')
		mlx_put_image_to_window
		(game->mlx, game->win, game->exit, i * 64, j * 64);
}

static void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[game->p_y + new_y][game->p_x + new_x] != '1')
	{
		ft_printf("%d\n", ++(game->n_moves));
		set_image(game, game->p_x, game->p_y);
		set_image(game, game->p_x + new_x, game->p_y + new_y);
		set_image(game, game->p_x + new_x, game->p_y + new_y);
		if (game->map[game->p_y + new_y][game->p_x + new_x] == 'C')
		{
			game->n_collect--;
			if (game->n_collect == 0 && game->map[game->p_y][game->p_x] != 'E')
			{
				ft_printf("The player has reached the exit. So long!\n");
				exit(0);
			}
		}
		game->p_x = game->p_x + new_x;
		game->p_y = game->p_y + new_y;
		if (game->map[game->p_y][game->p_x] != 'E')
			game->map[game->p_y][game->p_x] = '0';
	}
	printf("yes\n");
}*/



/*void	create_window(t_game *game)
{
	int		i;
	int		j;

	load_image(game);
	j = 0;
	while (j < game->map_height)
	{
		i = 0;
		while (i < game->map_width)
		{
			set_image(game, j, i);
		i++;
		}
	j++;
	}
}*/
static void	put_image(t_game *game, int y, int x, char *sprite)
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
	int		x;
	int		y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == '1')
				put_image(game, x, y, "wall.xpm");
			else
				put_image(game, x, y, "background.xpm");
			if (game->map[y][x] == 'C')
				put_image(game, x, y, "bottle.xpm");
			else if (game->map[y][x] == 'P')
				put_image(game, x, y, "Mermaid.xpm");
			else if (game->map[y][x] == 'E')
				put_image(game, x, y, "Exit.xpm");
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
		put_image(game, game->p_x, game->p_y, "Background.xpm");
		put_image(game, game->p_x + new_x, game->p_y + new_y, "Background.xpm");
		put_image(game, game->p_x + new_x, game->p_y + new_y, "Mermaid.xpm");
		if (game->map[game->p_y + new_y][game->p_x + new_x] == 'C')
		{
			game->n_collect--;
			/*if (game->n_collect == 0)
				put_image(game, game->e_x, game->e_y, "exit.xpm");*/
		}
		game->p_x = game->p_x + new_x;
		game->p_y = game->p_y + new_y;
		if (game->map[game->p_y][game->p_x] != 'E')
			game->map[game->p_y][game->p_x] = '0';
		else if (game->n_collect == 0 && game->map[game->p_y][game->p_x] == 'E')
		{
			ft_printf("\033[0;32mThe player has reached the exit. So long!\n");
			exit(0);
		}
	}
}

int	event_handler(enum e_direction key, t_game *game)
{
	if (key == ESC)
		close_window(game);
	else if (key == W)
		move_player(game, 0, -1);
	else if (key == A)
		move_player(game, -1, 0);
	else if (key == S)
		move_player(game, 0, 1);
	else if (key == D)
		move_player(game, 1, 0);
	return (0);
}

