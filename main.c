/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:45:06 by cdine             #+#    #+#             */
/*   Updated: 2022/02/01 12:38:39 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_program	solong;

	solong.map = ft_putmapintab(argv[1]);
	if (argc != 2 || solong.map == NULL
		|| ft_checkmap(argv[1], solong.map) != 1)
	{
		if (solong.map == NULL)
			ft_error(argc, 7);
		else
		{
			ft_error(argc, ft_checkmap(argv[1], solong.map));
			ft_destroy_error(&solong);
		}
		return (0);
	}
	solong.mlx = mlx_init();
	solong.win = ft_new_window(solong.mlx, ft_strlen(solong.map[0]) * 32,
			ft_map_lines(solong.map) * 32, "FEED THE CAT!");
	if (!solong.mlx)
		return (1);
	ft_init_var(&solong);
	ft_init_map(&solong);
	mlx_hook(solong.win.ref, 17, 0, ft_close, &solong);
	mlx_key_hook(solong.win.ref, &ft_keyhook, &solong);
	mlx_loop(solong.mlx);
}
