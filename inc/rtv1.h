/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 16:42:15 by npineau           #+#    #+#             */
/*   Updated: 2015/05/21 16:21:59 by npineau          ###   ########.fr       */
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

typedef struct		s_env
{
	void			*mlx;
	t_object		objects[MAX_OBJECTS];
	t_light			lights[MAX_LIGHTS];
	t_camera		camera[MAX_CAMERAS];
	t_win			win;
	t_img			img;
}					t_env;

int					key_press(int key, t_env const *env);
int					update_screen(t_env const *env);
#endif
