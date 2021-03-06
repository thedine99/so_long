/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_msg_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:12:56 by cdine             #+#    #+#             */
/*   Updated: 2022/02/01 12:22:21 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_display_fish_count(t_program *solong)
{
	char	*count;

	mlx_string_put((*solong).mlx, (*solong).win.ref, 90,
		ft_map_lines((*solong).map) * 32 + 34, 255255255, "Fish caught:");
	count = ft_itoa((*solong).fish_caught, solong);
	mlx_string_put((*solong).mlx, (*solong).win.ref, 165,
		ft_map_lines((*solong).map) * 32 + 34, 255255255, count);
	free(count);
	mlx_string_put((*solong).mlx, (*solong).win.ref, 185,
		ft_map_lines((*solong).map) * 32 + 34, 255255255, "/");
	count = ft_itoa((*solong).nb_fish_total, solong);
	mlx_string_put((*solong).mlx, (*solong).win.ref, 195,
		ft_map_lines((*solong).map) * 32 + 34, 255255255, count);
	free(count);
}

void	ft_display_move_count(t_program *solong)
{
	char	*count;

	mlx_string_put((*solong).mlx, (*solong).win.ref, 16,
		ft_map_lines((*solong).map) * 32 + 34, 255255255, "Moves:");
	count = ft_itoa((*solong).move_count, solong);
	mlx_string_put((*solong).mlx, (*solong).win.ref, 55,
		ft_map_lines((*solong).map) * 32 + 34, 255255255, count);
	free(count);
}

void	ft_display_which_msg(t_program *solong, int msg)
{
	if (msg == 0)
	{
		mlx_string_put((*solong).mlx, (*solong).win.ref, 16,
			ft_map_lines((*solong).map) * 32 + 20, 255255255,
			"Meow is hungry. Get some fish pls.");
	}
	else if (msg == 1)
	{
		mlx_string_put((*solong).mlx, (*solong).win.ref, 16,
			ft_map_lines((*solong).map) * 32 + 20, 255255255,
			"You got killed by the reaper! Press esc to exit.");
	}
	else if (msg == 2)
	{
		mlx_string_put((*solong).mlx, (*solong).win.ref, 16,
			ft_map_lines((*solong).map) * 32 + 20, 255255255,
			"You won! Press esc to exit.");
	}
	else if (msg == 3)
	{
		mlx_string_put((*solong).mlx, (*solong).win.ref, 16,
			ft_map_lines((*solong).map) * 32 + 20, 255255255,
			"Reaper is stucked :(");
	}
}

void	ft_display_msg(t_program *solong, int msg)
{
	mlx_clear_window((*solong).mlx, (*solong).win.ref);
	ft_display_which_msg(solong, msg);
	ft_display_move_count(solong);
	ft_display_fish_count(solong);
	ft_init_map(solong);
	ft_redraw_map(solong);
}
