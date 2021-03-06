/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdine <cdine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:32:16 by cdine             #+#    #+#             */
/*   Updated: 2022/01/27 23:04:21 by cdine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_window	ft_new_window(void *mlx, int width, int height, char *name)
{
	t_window	win;

	win.ref = mlx_new_window(mlx, width, height, name);
	win.size.x = width;
	win.size.y = height;
	return (win);
}

t_image	ft_new_sprite(t_program *solong, char *path)
{
	t_image	img;

	img.ref = mlx_xpm_file_to_image((*solong).mlx, path, &img.size.x,
			&img.size.y);
	if (img.ref == NULL)
		ft_close(solong);
	(*solong).nb_sprite++;
	img.addr = mlx_get_data_addr(img.ref, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	return (img);
}

void	ft_init_sprite_reaper_left(t_program *solong)
{
	t_image	sprite;

	sprite = ft_new_sprite(solong, "./img/deatha.xpm");
	(*solong).spriteref[16] = sprite.ref;
	sprite = ft_new_sprite(solong, "./img/deathb.xpm");
	(*solong).spriteref[17] = sprite.ref;
	sprite = ft_new_sprite(solong, "./img/deathc.xpm");
	(*solong).spriteref[18] = sprite.ref;
	sprite = ft_new_sprite(solong, "./img/deathd.xpm");
	(*solong).spriteref[19] = sprite.ref;
	sprite = ft_new_sprite(solong, "./img/deathe.xpm");
	(*solong).spriteref[20] = sprite.ref;
	sprite = ft_new_sprite(solong, "./img/deathf.xpm");
	(*solong).spriteref[21] = sprite.ref;
	sprite = ft_new_sprite(solong, "./img/deathg.xpm");
	(*solong).spriteref[22] = sprite.ref;
}
