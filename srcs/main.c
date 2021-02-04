

#include "../includes/minishell.h"

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;

	char 	*line;
//	char	c;
//	int		i;

	while (1) {
		ft_printf("minishell: ");
		get_next_line(0, &line);
		if (ft_strncmp(line, "exit", 4) == 0)
			exit(0);
		if (ft_strncmp(line, "echo ", 4) == 0)
		{
			ft_printf("%s\n", line + 5);
		}
	}
	return (0);
}
