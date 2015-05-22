/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 19:36:19 by npineau           #+#    #+#             */
/*   Updated: 2015/05/22 19:36:23 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 16:42:15 by npineau           #+#    #+#             */
/*   Updated: 2015/05/22 17:58:23 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft.h"
# include "libumlx.h"
# include "libmtx.h"
# include "util.h"
# include "shapes.h"
# include "parser.h"

# define MAX_LIGHTS 20
# define MAX_OBJECTS 20
# define MAX_CAMERAS 20

# define WIDTH 1366
# define HEIGTH 768
# define FOV 90

typedef struct		s_env
{
	void			*mlx;
	t_object		objects[MAX_OBJECTS];
	t_light			lights[MAX_LIGHTS];
	t_camera		cameras[MAX_CAMERAS];
	t_win			win;
	t_img			img;
	size_t			nb_object;
	size_t			nb_light;
	size_t			nb_camera;
	unsigned int	current_camera;
}					t_env;

void				atom_to_struct(t_atom atom, t_env *env);
int					key_press(int key, t_env const *env);
int					scene_to_struct(char const *path, t_env *env);
int					update_screen(t_env const *env);
#endif
