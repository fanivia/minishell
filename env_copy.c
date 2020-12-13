

#include "includes/minishell.h"

char 	**copy_env(char **env)
{
	int		i;
	char 	**res;

	i = 0;
	while (env[i])
		i++;
	if (!(res = (char **)ft_calloc(sizeof(char *), i + 1)))
		return (NULL);
	i = 0;
	while (env[i])
	{
		res[i] = ft_strjoin(env[i], "");
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	create_filename(char *path, char *cmd, char *file_name[2])
{
	if (!(file_name[0] = (char *)ft_calloc(sizeof(char),
			   (ft_strlen(cmd) + ft_strlen(path) + 2))))
		return ;
	file_name[0] = ft_strlcat(file_name[0], path, sizeof(ft_strlen(path)));
	file_name[0] = ft_strlcat(file_name[0], "/", 1);
	file_name[0] = ft_strlcat(file_name[0], cmd);
}
