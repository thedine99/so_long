/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:25:08 by cdine             #+#    #+#             */
/*   Updated: 2022/01/27 21:59:40 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_checkway(t_program *solong, char dir, int row, int col)
{
	if (dir == 'l')
	{
		if ((*solong).map[row][col - 1] == '1' || ((*solong).map[row][col - 1]
			== 'E' && (*solong).fish_caught != (*solong).nb_fish_total))
			return (0);
	}
	if (dir == 'r')
	{
		if ((*solong).map[row][col + 1] == '1' || ((*solong).map[row][col + 1]
			== 'E' && (*solong).fish_caught != (*solong).nb_fish_total))
			return (0);
	}
	if (dir == 'u')
	{
		if ((*solong).map[row - 1][col] == '1' || ((*solong).map[row - 1][col]
			== 'E' && (*solong).fish_caught != (*solong).nb_fish_total))
			return (0);
	}
	if (dir == 'd')
	{
		if ((*solong).map[row + 1][col] == '1' || ((*solong).map[row + 1][col]
			== 'E' && (*solong).fish_caught != (*solong).nb_fish_total))
			return (0);
	}
	return (1);
}

void	ft_editmap_2(int row, int col, char c, t_program *solong)
{
	if ((*solong).map[row][col] == 'C')
		(*solong).fish_caught += 1;
	if ((*solong).map[row][col] == 'E')
		(*solong).win_lose = 1;
	else
		(*solong).map[row][col] = c;
}

int	ft_editmap(t_program *solong, char dir, int row, int col)
{
	(*solong).map[row][col] = '0';
	if (dir == 'l')
		ft_editmap_2(row, col - 1, 'L', solong);
	if (dir == 'r')
		ft_editmap_2(row, col + 1, 'R', solong);
	if (dir == 'd')
		ft_editmap_2(row + 1, col, 'D', solong);
	if (dir == 'u')
		ft_editmap_2(row - 1, col, 'U', solong);
	(*solong).move_count += 1;
	if (ft_get_position_col(solong, 'P') == -1)
		ft_display_msg(solong, 2);
	else
		ft_display_msg(solong, 0);
	ft_redraw_map(solong);
	ft_checkdeath(solong);
	if ((*solong).win_lose != -1)
		ft_move_reaper(solong, row, col);
	ft_checkdeath(solong);
	ft_redraw_map(solong);
	return (1);
}

void	ft_move(char dir, t_program *solong)
{
	int	row;
	int	col;
	int	moved;

	moved = 0;
	row = 0;
	while ((*solong).map[row][0])
	{
		col = 0;
		while ((*solong).map[row][col])
		{
			if ((*solong).map[row][col] == 'P' || (*solong).map[row][col] == 'L'
				|| (*solong).map[row][col] == 'R' || (*solong).map[row][col]
				== 'D' || (*solong).map[row][col] == 'U')
			{
				ft_checkdeath(solong);
				if (ft_checkway(solong, dir, row, col) == 1)
					moved = ft_editmap(solong, dir, row, col);
			}
			if (moved == 1)
				break ;
			col++;
		}
		row++;
	}
}

int	ft_keyhook(int keycode, t_program *solong)
{
	if (keycode == XK_Escape)
		ft_close(solong);
	if ((*solong).win_lose > -1)
	{
		if (keycode == XK_a)
			ft_move('l', solong);
		if (keycode == XK_d)
			ft_move('r', solong);
		if (keycode == XK_w)
			ft_move('u', solong);
		if (keycode == XK_s)
			ft_move('d', solong);
	}
	return (0);
}
