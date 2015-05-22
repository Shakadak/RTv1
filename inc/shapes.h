/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 19:36:31 by npineau           #+#    #+#             */
/*   Updated: 2015/05/22 19:36:34 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "rtv1.h"

typedef struct	s_camera
{
	t_pipe		transform;
	t_pos		screen;
	double		fov;
}				t_camera;

typedef struct	s_ray
{
	t_mtx		pos;
	t_mtx		dir;
}				t_ray;

typedef struct	s_light
{
	t_mtx		pos;
	double		intensity;
	int			defined;
}				t_light;

typedef struct	s_object
{
	t_pipe		pipe;
	t_mtx		quadric;
	t_color		rgb;
	int			defined;
}				t_object;

t_object		new_cone(t_pipe const pipe, t_color const color);
t_object		new_cylinder(t_pipe const pipe, t_color const color);
t_object		new_sphere(t_pipe const pipe, t_color const color);
t_object		new_plane(t_pipe const pipe, t_color const color);
t_camera		new_camera(
		t_mtx const pos,
		t_mtx const direction,
		t_pos const screen);
t_light	new_light(t_mtx const coordinate, double const intensity);
t_ray			ray_new(t_camera const camera,
		t_pos const pos);
t_color			ray_cast(t_pos const pos,
		t_camera const camera,
		t_object *objects,
		t_light const *lights);
t_ray			ray_normal(t_object const obj,
		t_ray const ray,
		double const dist);
t_color			ray_shade(t_object obj,
		t_ray const ray,
		double const dist,
		t_object const *objects,
		t_light const *light);
double			intersec_quadric(t_object const object, t_ray const ray);
t_ray			ray_transform(t_ray const ray, t_pipe const pipe);

#endif
