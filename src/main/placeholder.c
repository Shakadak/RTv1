#include <fcntl>
#include "rtv1.h"

void	line_to_struct(char const line, t_env *env)
{
	char	**array;

	array = ft_strxsplit(line, ft_isspace);
	if (ft_strcmp(array[0], "LIGHT"))
		set_light(array, env);
	ft_freesplit(array);
}

int		scene_to_struct(char const *path, t_env *env)
{
	char	*line;
	int		fd;
	int		ret;

	if ((fd = open(path, O_RDONLY)) < 0)
		return (fd);
	while (ret = get_next_line(fd, &line) > 0)
	{
		line_to_struct(line, env);
		free(line);
	}
	free(line);
	return (ret);
}
