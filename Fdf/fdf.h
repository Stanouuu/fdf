/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 20:08:12 by stan              #+#    #+#             */
/*   Updated: 2022/07/11 14:07:21 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <math.h>
#include "minilibx-linux/mlx.h"
#include "gnl/get_next_line.h"
#include "Libft/libft.h"
#include "minilibx-linux/mlx_int.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		map;
	t_img img;
} t_data;

typedef struct s_pixels
{
	int				ypixel;
	int				xpixel;
	struct s_pixels *right;
	struct s_pixels *down;
} t_pixels;

typedef struct s_line
{
	char			**content;
	struct s_line	*next;
} t_line;

#endif
