/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_to_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npineau <npineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 19:30:03 by npineau           #+#    #+#             */
/*   Updated: 2015/05/22 19:30:05 by npineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "rtv1.h"

static void	line_to_struct(char const *line, t_env *env)
{
	char	**array;

	array = ft_strxsplit(line, ft_isspace);
	atom_to_struct(atom_fill((char const *const *const)array), env);
	ft_freesplit((void **)array);
}

int			scene_to_struct(char const *path, t_env *env)
{
	char	*line;
	int		fd;
	int		ret;

	if ((fd = open(path, O_RDONLY)) < 0)
	{
		ft_putendl_fd("Error while trying to open the scene", 2);
		return (fd);
	}
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_putendl(line);
		line_to_struct(line, env);
		free(line);
	}
	free(line);
	close(fd);
	return (ret);
}
