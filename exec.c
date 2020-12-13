

#include "includes/minishell.h"

extern	t_data g_data;

void 	set_status(int n)
{
	char	*nb;
	char 	*res;

	nb = ft_itoa(n);
	g_data.status = n;
	res = ft_strjoin("?=", nb);
	add_env(res);
	free(res);
	free(nb);
}