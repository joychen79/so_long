/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:15:01 by jingchen          #+#    #+#             */
/*   Updated: 2023/07/11 20:13:20 by jingchen         ###   ########.fr       */
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
		return (0);
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

static void	check_element(char **map)
{
	int			y;
	int			i;
	static int	p = 0;
	static int	c = 0;
	static int	e = 0;

	y = 0;
	while (map[y++])
	{
		i = 0;
		while (gmap[y++][i++])
		{
			if (map[y][i] == 'P')
				p += 1;
			if (map[y][i] == 'C')
				c += 1;
			if (map[y][i] == 'E')
				e += 1;
			if (map[y][i] != 'P' && map[y][i] != 'C'
				&& map[y][i]!= 'E' && map[y][i] != '1' && map[y][i] != '0')
				return (0)
		}
	}
	if (p != 1 || e != 1 || c < 1)
		return (0);

	return (1);
}

static int flood_map(t_game *game)
{
	
}

static void	*get_map(t_game *game, int fd)
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
	game->map_width = ft_strlen(line);
	game->map_height = i;
	free (line);
	free (file);
}

void	read_map(char **argv, t_game *game)
{
	int		fd;
	char	*extension;

	extension = ft_strchr(argv[1], '.');
	if (!extension || ft_strncmp(extension, ".ber", ft_strlen(extension)))
		print_errors("Invalid Map Extension!");
	fd = open (argv[1], O_RDONLY);
	if (fd <= 0)
		print_errors("Map Not Found!");
	if (read(fd, 0, 1) == 0)
		print_errors("Empty Map!");
	get_map(game, fd);
	if (check_walls(game) != 1 || check_element(game) != 1
		|| flood_map(game) != 1)
	{
		if (game)
			free(map);
		print_errors("Invalid Map");
	}
}*/



static int	check_walls(t_game *game)
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

static void	check_element(char **map)
{
	int			y;
	int			i;
	static int	p = 0;
	static int	c = 0;
	static int	e = 0;

	y = 0;
	while (map[y++])
	{
		i = 0;
		while (map[y++][i++])
		{
			if (map[y][i] == 'P')
				p += 1;
			if (map[y][i] == 'C')
				c += 1;
			if (map[y][i] == 'E')
				e += 1;
			if (map[y][i] != 'P' && map[y][i] != 'C'
				&& map[y][i] != 'E' && map[y][i] != '1' && map[y][i] != '0')
				print_errors("Invalid Map");
		}
	}
	if (p != 1 || e != 1 || c < 1)
		print_errors("Invalid Map");
}

static void	check_accesible(char **map, int x, int y)
{
	char	**copy_map;

	copy_map = map;
	copy_map[y][x] = 'F';
	if (copy_map[y + 1][x] != '1' && copy_map[y + 1][x] != 'F')
		check_accesible(copy_map, x, y + 1);
	if (copy_map[y - 1][x] != '1' && copy_map[y - 1][x] != 'F')
		check_accesible(copy_map, x, y - 1);
	if (copy_map[y][x + 1] != '1' && copy_map[y][x + 1] != 'F')
		check_accesible(copy_map, x + 1, y);
	if (copy_map[y][x - 1] != '1' && copy_map[y][x - 1] != 'F')
		check_accesible(copy_map, x - 1, y);
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
	game->map_width = ft_strlen(line);
	game->map_height = i;
	free (line);
	free (file);
}

void	read_map(char **argv, t_game *game)
{
	int		fd;
	char	*extension;

	extension = ft_strchr(argv[1], '.');
	if (!extension || ft_strncmp(extension, ".ber", ft_strlen(extension)))
		print_errors("Invalid Map Extension!");
	fd = open (argv[1], O_RDONLY);
	if (fd <= 0)
		print_errors("Map Not Found!");
	if (read(fd, 0, 1) == 0)
		print_errors("Empty Map!");
	get_map(game, fd);
	check_walls(game->map);
	check_element(game->map);
	check_accesible(game->map, game->p_x, game->p_y);
}


/*#include <fcntl.h>
int main (int ac, char **av)
// int main ()
{
	t_game *game;
	(void)ac;

	
	game = NULL;
	if (ac != 2)
		//error;
	else
	// else
	// {
		
		read_map(av,game);
	// }
	
}
*/