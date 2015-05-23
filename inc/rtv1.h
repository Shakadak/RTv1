/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 19:36:19 by npineau           #+#    #+#             */
/*   Updated: 2015/05/23 09:27:48 by npineau          ###   ########.fr       */
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

# define WIDTH 1366
# define HEIGTH 768
# define FOV 90

void				atom_to_struct(t_atom atom, t_env *env);
int					key_press(int key, t_env const *env);
int					scene_to_struct(char const *path, t_env *env);
int					update_screen(t_env const *env);
#endif
