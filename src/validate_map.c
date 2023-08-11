/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:46:13 by jingchen          #+#    #+#             */
/*   Updated: 2023/08/11 19:24:18 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/so_long.h"

static int	check_walls(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		if ((int)ft_strlen (game->map[y]) != game->map_width)
			return (0);
		else if (y == 0 || y == game->map_height - 1)
		{
			x = 0;
			while (game->map[y][x])
			{
				if (game->map[y][x] != '1')
					return (0);
				x++;
			}
		}	
		else if (game->map[y][0] != '1'
				|| game->map[y][game->map_width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

static int	check_element(t_game *game, char c)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == c)
				count++;
			else if (game ->map[y][x] != 'C' && game ->map[y][x] != 'P'
				&& game ->map[y][x] != 'E' && game ->map[y][x] != '1'
				&& game ->map[y][x] != '0')
			{
				print_errors("Map contains inllegal elements");
				return (0);
			}
		x++;
		}
	y++;
	}
	return (count);
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
}

static int	check_accesible(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	set_player(game, &game->p_x, &game->p_y, 'P');
	flood(game->check_map, game->p_x, game->p_y);
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->check_map[y][x] == 'C' || game->check_map[y][x] == 'E')
				return (0);
			x++;
		}
	y++;
	}
	return (1);
}

void	validate_map(t_game *game)
{
	set_player (game, &game->p_x, &game->p_y, 'P');
	if (check_walls(game) != 1 || check_element(game, 'P') != 1
		|| check_element(game, 'E') != 1
		|| check_element(game, 'C') < 1
		|| check_accesible(game) != 1)
	{
		if (game)
		{
			free(game);
		}
		print_errors("Invalid Map");
	}
	game->n_collect = check_element(game, 'C');
}

	/*if (check_accesible(game) != 1)
		print_errors("Map is inaccesible.");
	if (check_walls(game) != 1)
		print_errors("Map must be rectangular and closed by walls.");
	if (check_element(game, 'P') != 1)
		print_errors("Map must have one player starting position.");
	if (check_element(game, 'E') != 1)
		print_errors("Map must have one exit.");
	if (check_element(game, 'C') < 1)
	{
		print_errors("Map must have at least one coin.");
		return(0);
	}
	else
		return (1);*/