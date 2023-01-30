/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:15:49 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/30 11:08:22 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

//function to move the player to the right
void	ft_d(t_var *var)
{
	double	new_x;
	double	new_y;
	double	radians;

	radians = (90 - var->plr->p_angle) * M_PI / 180;
	new_x = var->plr->pos_x - 5 * cos(radians);
	new_y = var->plr->pos_y + 5 * sin(radians);
	if (!ft_is_wall(var, new_x, new_y))
	{
		var->plr->pos_x = new_x;
		var->plr->pos_y = new_y;
	}
}

// opens minimap
void	ft_m(t_var *var)
{
	var->map->minimap++;
	if (var->map->minimap % 2 == 0)
		var->map->minimap = 0;
}

//rotates the player to the left or right
void	ft_lr_arrows(t_var *var, int arrow)
{
	if (arrow == L_ARROW)
	{
		if (var->plr->p_angle == 0)
			var->plr->p_angle = 360;
		var->plr->p_angle -= 5;
	}
	else if (arrow == R_ARROW)
		var->plr->p_angle += 5;
	if (var->plr->p_angle > 359)
		var->plr->p_angle = 0.0;
}
