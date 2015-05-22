/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atom_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 19:30:15 by npineau           #+#    #+#             */
/*   Updated: 2015/05/22 19:30:19 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_atom	get_fill(t_atom atom, char const *const *const src, int *i)
{
	if (!ft_strcmp(src[*i], "CAMERA"))
		atom.type = CAMERA;
	else if (!ft_strcmp(src[*i], "LIGHT"))
		atom.type = LIGHT;
	else if (!ft_strcmp(src[*i], "CYLINDER"))
		atom.type = CYLINDER;
	else if (!ft_strcmp(src[*i], "CONE"))
		atom.type = CONE;
	else if (!ft_strcmp(src[*i], "PLANE"))
		atom.type = PLANE;
	else if (!ft_strcmp(src[*i], "SPHERE"))
		atom.type = SPHERE;
	else if (!ft_strcmp(src[*i], "SCALE"))
		atom.scale = fill_transformation(src, i);
	else if (!ft_strcmp(src[*i], "ROTATION"))
		atom.rotation = fill_transformation(src, i);
	else if (!ft_strcmp(src[*i], "TRANSLATION"))
		atom.translation = fill_transformation(src, i);
	else if (!ft_strcmp(src[*i], "COLOR"))
		atom.color = fill_color(src, i);
	else if (!ft_strcmp(src[*i], "INTENSITY"))
		atom.intensity = ft_atof(src[++(*i)]);
	else
		ft_fatal("Error while parsing file.", 0);
	return (atom);
}

t_atom			atom_fill(char const *const *const array)
{
	int		i;
	t_atom	atom;

	i = 0;
	atom = atom_new();
	while (array[i] != NULL)
	{
		atom = get_fill(atom, array, &i);
		++i;
	}
	return (atom);
}
