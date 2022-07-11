/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 20:31:52 by stan              #+#    #+#             */
/*   Updated: 2022/07/11 14:39:29 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void img_pix_put(t_img *img, int x, int y, int color)
{
	char *pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	find_line(t_line *line, t_data *data)
{
	while (line->content)
	{
		line->content = split(get_next_line(data->map), ' ');
		line = line->next;
	}
}

int	count_line(t_line *line)
{
	int	i;

	i = 0;
	while (line)
	{
		line = line->next;
		i++;
	}
	return (i);
}

void find_pixels(t_pixels *pixels, t_line *line, int i, int	j)
{
	if (line->content[i])
	{
		pixels->ypixel = 600 - (100 * j);
		find_pixels(pixels, line, i++, j);
	}
}

int	render(t_data *data)
{
	int			i;
	int			j;
	t_img		*img;
	t_line		*line;
	t_pixels	 *pixels;

	img = &data->img;
	i = 0;
	j = 0;
	find_line(line, data);
	find_pixels(pixels, line, 0, 0);
	while (i < 100)
	{
		j = 0;
		while (j < 100)
			img_pix_put(img, j++, i, 0xFFFFFF);
		++i;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

int handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (0);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 700, "FDF");
	if (!data.win_ptr)
	{
		free(data.win_ptr);
		return (0);
	}
	data.map = open("maps/42.fdf", O_RDONLY);
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, 600, 700);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_key_hook(data.win_ptr, &handle_input, &data);

	mlx_loop(data.mlx_ptr);

	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
