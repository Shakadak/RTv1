/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 16:42:15 by npineau           #+#    #+#             */
/*   Updated: 2015/02/16 16:57:21 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

typedef enum	e_kind
{
	SPHERE,
	PLANE,
	TOTAL
}				t_kind;

typedef struct	s_sphere
{
	int			cc;
}				t_sphere;

typedef struct	s_plane
{
	int			cc;
}				t_plane;

typedef union	u_shape
{
	t_sphere	sphere;
	t_plane		plane;
}				t_shape;

typedef struct	s_object
{
	t_kind		kind;
	t_shape		shape;
}				t_object;

#endif
