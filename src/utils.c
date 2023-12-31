/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:42:49 by jingchen          #+#    #+#             */
/*   Updated: 2023/08/14 17:22:52 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/so_long.h"

void	print_errors(char *errors)
{
	ft_printf("%s", errors);
	exit(1);
}

void	set_element(t_game *game, int *x, int *y, char item)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map_width)
	{
		j = 0;
		while (j < game->map_height)
		{
			if (game->map[j][i] == item)
			{
				*x = i;
				*y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->map);
	exit(0);
}
