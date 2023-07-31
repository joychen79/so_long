/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:15:01 by jingchen          #+#    #+#             */
/*   Updated: 2023/07/31 19:29:58 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/so_long.h"


/*static void	check_extension(char *mapname)
{
		extension = ft_strchr(mapname, '.');
	if (!extension || ft_strncmp(extension, ".ber", ft_strlen(extension)))
		print_errors("Invalid Map Extension!");
}*/

/*static int	check_walls(t_game *game)
{
	int	y;
	int	i;

	if (game->map == NULL)
		print_errors("Invalid Map");
	y = 0;
	while (game->map[y])
	{
		if (ft_strlen (game->map[y]) != game->map_width)
			return (0);
		else if (y == 0 || game->map[y + 1] == NULL)
		{
			i = 0;
			while (game->map[y][i])
			{
				if (game->map[y][i] != '1')
					return (0);
				i++;
			}
		}	
		else if (game->map[y][0] || game->map[y][game->map_width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

static int	check_element(t_game *game, char c)
{
	int	y;
	int	i;
	int	count;

	y = 0;
	count = 0;
	while (game->map[y])
	{
		i = 0;
		while (game->map[y][i])
		{
			if (game->map[y][i] == c)
			count++;
			if (game->map[y][i] == 'P')
			{
				game->p_y = y;
				game->p_x = i;
			}
		i++;
		}
		y++;
	}
	return (count);
}

static int	check_accesible(t_game *game)
{
	int	i;
	int	y;

	y = 0;
	flood(game->check_map, game->p_x, game->p_y);
	while (y < game->map_height)
	{
		i = 0;
		while (i < game->map_width)
		{
			if (game->check_map[y][i] != '1' &&
			game->check_map[y][i] != 'F' && game->check_map[y][i] != '0')
				return (0);
			i++;
		}
	y++;
	}
	return (1);
}

static void	flood(char **map, int x, int y)
{
	map[y][x] = 'F';
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'F')
		flood(map, x, y + 1);
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'F')
		flood(map, x, y - 1);
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'F')
		flood(map, x + 1, y);
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'F')
		flood(map, x - 1, y);
}*/



#include <fcntl.h>
int main (int ac, char **av)
{
	t_game	*game;
	(void)	ac;

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
	create_window(game);
	mlx_loop(game->mlx);
}
