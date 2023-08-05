/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:46:13 by jingchen          #+#    #+#             */
/*   Updated: 2023/08/05 18:35:02 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/so_long.h"

static int	check_walls(t_game *game)
{
	int	y;
	int	i;

	y = 0;
	while (game->map[y])
	{
		if ((int)ft_strlen (game->map[y]) != game->map_width)
			return (0);
		else if (y == 0 || y == game->map_height - 1)
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
			else if (game ->map[y][i] != 'C' && game ->map[y][i] != 'P'
				&& game ->map[y][i] != 'E' && game ->map[y][i] != '1'
				&& game ->map[y][i] != '0')
			{
				print_errors("Map contains inllegal elements");
				return (0);
			}
		i++;
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
	int	i;
	int	y;

	y = 0;
	i = 0;
	set_player (game, &game->p_x, &game->p_y, 'P');
	flood(game->check_map, game->p_x, game->p_y);
	while (y < game->map_height)
	{
		i = 0;
		while (i < game->map_width)
		{
			if (game->check_map[y][i] == 'C')
				return (0);
			i++;
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