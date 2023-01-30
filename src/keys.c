/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:09:03 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/30 11:07:29 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

//function to draw a pixel on the image at coord. x,y
void	img_pix_put(t_var *var, int x, int y, int color)
{
	char	*pixel;

	pixel = var->img->addr + (y * var->img->size_line + \
			x * (var->img->bpp / 8));
	*(unsigned int *)pixel = color;
}

//function that exits the game when X is pressed and free stuff
int	x_window(t_var *var)
{
	write(1, "Exited the game\n", 16);
	mlx_destroy_image(var->mlx->ptr, var->txt->texture_no);
	mlx_destroy_image(var->mlx->ptr, var->txt->texture_so);
	mlx_destroy_image(var->mlx->ptr, var->txt->texture_ea);
	mlx_destroy_image(var->mlx->ptr, var->txt->texture_we);
	mlx_destroy_image(var->mlx->ptr, var->img->structure);
	mlx_destroy_window(var->mlx->ptr, var->mlx->window);
	mlx_destroy_display(var->mlx->ptr);
	free(var->mlx->ptr);
	var->mlx->window = NULL;
	ft_free_struct(var);
	cleanup(var);
	free(var);
	exit(EXIT_SUCCESS);
	return (0);
}

//function to move the player forward
void	ft_w(t_var *var)
{
	double	new_x;
	double	new_y;
	double	radians;

	radians = (var->plr->p_angle) * M_PI / 180;
	new_x = var->plr->pos_x + 5 * cos(radians);
	new_y = var->plr->pos_y + 5 * sin(radians);
	if (!ft_is_wall(var, new_x, new_y))
	{
		var->plr->pos_x = new_x;
		var->plr->pos_y = new_y;
	}
}

//function to move the player to the left
void	ft_a(t_var *var)
{
	double	new_x;
	double	new_y;
	double	radians;

	radians = (90 - var->plr->p_angle) * M_PI / 180;
	new_x = var->plr->pos_x + 5 * cos(radians);
	new_y = var->plr->pos_y - 5 * sin(radians);
	if (!ft_is_wall(var, new_x, new_y))
	{
		var->plr->pos_x = new_x;
		var->plr->pos_y = new_y;
	}
}

//function to move the player backwards
void	ft_s(t_var *var)
{
	double	new_x;
	double	new_y;
	double	radians;

	radians = (var->plr->p_angle) * M_PI / 180;
	new_x = var->plr->pos_x - 5 * cos(radians);
	new_y = var->plr->pos_y - 5 * sin(radians);
	if (!ft_is_wall(var, new_x, new_y))
	{
		var->plr->pos_x = new_x;
		var->plr->pos_y = new_y;
	}
}
