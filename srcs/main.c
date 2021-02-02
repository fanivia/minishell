

#include "../includes/minishell.h"

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;

	char 	*line;
	char	c;
	int		i;

	while (1) {
		ft_printf("minishell: ");
		get_next_line(0, &line);
		if (!ft_memcmp(line, "exit", 5))
			exit(0);
		if (!ft_memcmp(line, "echo ", 5))
		{
			if (*(line + 5) != '"')
				ft_printf("%s\n", line + 5);
			else
			{
				ft_printf("%s\n", line + 6);
			}
		}
	}
	return (0);
}
