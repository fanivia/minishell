
#include "includes/minishell.h"

extern t_data g_data;

static int	get_env_index(char *var)
{
	int		i;
	char 	*key;

	i = 0;
	if(!(key = (char *)ft_calloc(sizeof(char), ft_strlen(var) + 2)))
		return (0);
	ft_strlcat(key, var, sizeof(ft_strlen(var)));
	ft_strlcat(key, "=", 1);
	while (g_data.env[i])
	{
		if (!ft_strncmp(g_data.env[i], key, ft_strlen(key)))
		{
			free(key);
			return (i);
		}
		++i;
	}
	free(key);
	return (-1);
}

void	add_env(char *var)
{
	char	**envp;
	char	**split;
	int 	i;

	i = 0;
	split = ft_split(var, '=');
	remove_env(split[0]);
	ft_free_array(split);
	while (g_data.env[i])
		i++;
	if (!(envp = (char **)ft_calloc(sizeof(char *), i + 2)))
		return ;
	i = 0;
	while (g_data.env[i])
	{
		envp[i] = ft_strjoin(g_data.env[i], "");
		i++;
	}
	envp[i] = ft_strjoin(var, "");
	ft_free_array(g_data.env);
	g_data.env = envp;
}

void		remove_env(char *var)
{
	int 	i;
	int 	j;
	char 	**res;
	int 	index;

	i = 0;
	if ((index = get_env_index(var)) == -1)
		return ;
	while (g_data.env[i])
		i++;
	if (!(res = (char **)ft_calloc(sizeof(char *), i + 1)))
		return ;
	i = 0;
	j = 0;
	while (g_data.env[i])
	{
		if (i != index)
			res[j++] = ft_strjoin(g_data.env[i], "");
		i++;
	}
	ft_free_array(g_data.env);
	g_data.env = res;
}
