/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_main_MOET.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanivia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 22:41:31 by fanivia           #+#    #+#             */
/*   Updated: 2020/11/27 22:41:33 by fanivia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <stdio.h>

static char	*dir_like_bash(char *dir)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (dir[i])
	{
		if (dir[i] != '/')
			count++;
		while (dir[i] != '/' && dir[i + 1])
			i++;
		i++;
	}
	i = 0;
	if (count < 2)
		return (ft_strdup(dir));
	else if (count == 2)
		return (ft_strdup("~"));
	while (*dir && i != 3)
		if (*dir++ == '/')
			i++;
	dir--;
	return (ft_strjoin("~", dir));
}

void		print_prompt(void)
{
	char	cwd[1024];
	char	*dir;
	t_data	g_data;

	dir = dir_like_bash(getcwd(cwd, sizeof(cwd)));
	if (g_data.status == 0)
		ft_printf(GREEN"minishellka"RESET":"CYAN"%s "GREEN"➜ "RESET, dir);
	else
		ft_printf(GREEN"minishellka"RESET":"CYAN"%s "RED"➜ "RESET, dir);
	free(dir);
}

void		print_prompt_minishellka(void)
{
	char	*input;
	char 	*trim_input;
	int 	ret;

	ret = 0;
	input = NULL;
	while (777)
	{
		print_prompt();
	}
}

t_data	g_data;

int			main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	g_data.env = copy_env(env);
	set_status(0);
	print_prompt_minishellka();
	return (0);
}

