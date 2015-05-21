#include "rtv1.h"
#include <math.h>

static t_object	new_object(t_atom atom)
{
	t_pipe	pipe;

	pipe = transform_pipeline(atom.scale,
			mtx_scalar_mult(M_PI / 180, atom.rotation), atom.translation);
	if (atom.type == CONE)
		return (new_cone(pipe, atom.color));
	else if (atom.type == CYLINDER)
		return (new_cylinder(pipe, atom.color));
	else if (atom.type == PLANE)
		return (new_plane(pipe, atom.color));
	else
		return (new_sphere(pipe, atom.color));
}

static int		is_object(t_type t)
{
	if (t == UNKNOWN)
		ft_fatal("Error while parsing, unknown type\n", 0);
	return (t == CYLINDER || t == CONE || t == SPHERE || t == PLANE);
}

void			atom_to_struct(t_atom atom, t_env *env)
{
	if (atom.type == LIGHT)
	{
		if (env->nb_light < MAX_LIGHTS)
			env->lights[(env->nb_light)++] = new_light(atom.translation,
					atom.intensity);
		else
			ft_fatal("Not enough space to add light\n", 0);
	}
	else if (atom.type == CAMERA)
	{
		if (env->nb_camera < MAX_CAMERAS)
			env->cameras[(env->nb_camera)++] = new_camera(atom.translation,
					atom.rotation, env->img.dim);
		else
			ft_fatal("Not enough space to add camera\n", 0);
	}
	else if (is_object(atom.type))
	{
		if (env->nb_object < MAX_OBJECTS)
			env->objects[(env->nb_object)++] = new_object(atom);
		else
			ft_fatal("Not enough space to add light\n", 0);
	}
}
