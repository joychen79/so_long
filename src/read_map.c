/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:40:56 by jingchen          #+#    #+#             */
/*   Updated: 2023/07/31 19:56:38 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/so_long.h"

static int	check_walls(t_game *game)
{
	int	y;
	int	i;

	if (game->map == NULL)
		print_errors("Invalid Map");
	y = 0;
	while (game->map[y])
	{
		if ((int)ft_strlen (game->map[y]) != game->map_width)
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
			if (game->map[y][i] == 'C')
				game->n_collect++;
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

static void	get_map(t_game *game, int fd)
{
	char	*file;
	char	*line;
	int		i;

	i = 1;
	line = get_next_line(fd);
	while (line)
	{
		file = ft_strjoin(file, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	game->map = ft_split(file, '\n');
	game->check_map = ft_split(file, '\n');
	game->map_width = ft_strlen(line);
	game->map_height = i;
	free (line);
	free (file);
}

/* void	sl_check_file(char *file)
{
	char	*file_ext;

	file_ext = ft_strrchr(file, '.');
	if (!file_ext || ft_strncmp(file_ext, ".ber", ft_strlen(file)) != 0)
		sl_error(EXTENSION);
} */

void	read_map(char **argv, t_game *game)
{
	int		fd;
	char	*extension;

	extension = ft_strrchr(argv[1], '.');
	if (!extension || ft_strncmp(extension, ".ber", ft_strlen(extension)))
		print_errors("Invalid Map Extension!");
	fd = open (argv[1], O_RDONLY);
	if (fd <= 0)
		print_errors("Map Not Found!");
	if (read(fd, 0, 1) == 0)
		print_errors("Empty Map!");
	get_map(game, fd);
	if (check_walls(game) != 1 || check_element(game, 'P') != 1
		|| check_element(game, 'E') != 1
		|| check_element(game, 'C') < 1
		|| check_accesible(game) != 1)
	{
		if (game)
			free(game);
		print_errors("Invalid Map");
	}
}
