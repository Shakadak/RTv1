/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 16:42:15 by npineau           #+#    #+#             */
/*   Updated: 2015/04/09 16:29:05 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft.h"
# include "libumlx.h"
# include "libmtx.h"
# include "util.h"
# include "shapes.h"

typedef struct		s_env
{
	void			*mlx;
	t_object		objects[20];
	t_light			lights[20];
	t_camera		camera;
	t_win			win;
	t_img			img;
}					t_env;

int					key_press(int key);
int					update_screen(t_env const *env);
#endif
