/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:40:56 by jingchen          #+#    #+#             */
/*   Updated: 2023/08/05 18:49:02 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/so_long.h"

static void	check_extension(char **argv)
{
	char	*extension;

		extension = ft_strrchr(argv[1], '.');
	if (!extension || ft_strncmp(extension, ".ber", ft_strlen(extension)))
		print_errors("Invalid Map Extension!");
}

static char	*get_map(t_game *game, int fd)
{
	char	*file;
	char	*line;

	line = get_next_line(fd);
	file = ft_calloc(1, 1);
	if (!file)
		exit(1);
	game->map_width = ft_strlen(line);
	while (line != NULL)
	{
		file = ft_strjoin(file, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (file);
}

void	read_map(char **argv, t_game *game)
{
	char	*file;
	int		fd;
	int		i;

	check_extension(argv);
	fd = open (argv[1], O_RDONLY);
	if (fd <= 0)
		print_errors("Map Not Found!");
	if (read(fd, 0, 1) == 0)
		print_errors("Empty Map!");
	file = get_map(game, fd);
	close(fd);
	game->map = ft_split(file, '\n');
	game->check_map = ft_split(file, '\n');
	game->map_width = ft_strlen(*(game->map));
	i = 0;
	while (game->map[i++] != NULL)
		game->map_height++;
	validate_map(game);
	free(file);
}
