/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_colours.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bposa <bposa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:42:35 by jwadding          #+#    #+#             */
/*   Updated: 2025/07/30 22:06:31 by bposa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

/*
	If any channel is > 255.0f we scale each channel down so that the biggest one
	is 255.0 and other values stay proportional.
*/
static t_rgb	scale_colour_channels(t_rgb a)
{
	float		max_value;
	float		scale;

	if (a.r > 255.0f || a.g > 255.0f || a.b > 255.0f)
	{
		max_value = fmaxf(fmaxf(a.r, a.g), a.b);
		scale = 255.0f / max_value;
		a.r *= scale;
		a.g *= scale;
		a.b *= scale;
	}
	return (a);
}

t_rgb	add_colours(t_rgb a, t_rgb b)
{
	t_rgb	c;

	c.r = a.r + b.r;
	c.g = a.g + b.g;
	c.b = a.b + b.b;
	return (scale_colour_channels(c));
}

t_rgb	scale_colour(t_rgb a, float scaler)
{
	t_rgb	c;

	c.r = a.r * scaler;
	c.g = a.g * scaler;
	c.b = a.b * scaler;
	return (scale_colour_channels(c));
}

t_rgb	hadamard_product(t_rgb a, t_rgb b)
{
	t_rgb	c;

	c.r = (a.r * b.r) / 255.0;
	c.g = (a.g * b.g) / 255.0;
	c.b = (a.b * b.b) / 255.0;
	return (scale_colour_channels(c));
}

float	clamp(float n)
{
	if (n > 255.0)
		return (255.0);
	if (n < 0.0)
		return (0.0);
	return (n);
}
