/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 16:42:15 by npineau           #+#    #+#             */
/*   Updated: 2015/02/24 17:52:18 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft.h"
# include "libumlx.h"
# include "shapes.h"

typedef struct		s_ray
{
	t_vtx			origin;
	t_vtx			direction;
}					t_ray;

#endif
