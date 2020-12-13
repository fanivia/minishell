

#include "../includes/minishell.h"

//void	print_minishell(void)
//{
//
//}
//
////typedef struct s_input
//
//int good_line()
//{
//	stract bla;
//	while(buf != NULL)
//	{
//		parser(buf, &stract);
//		executer(stract);
//	}
//	return;
//}


int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;

//	char	buf[1024];
	char 	*line;
	char	c;
	int		i;

	while (1)
	{
		ft_printf("minishell"":");
		get_next_line(0, &line);
//		ft_strlcpy(buf, line, ft_strlen(line) + 1);
//		free(line);
		i = 0;
		while (i < 5 && line[i])
		{
			if (ft_strncmp(line, "echo", 4) == 0)
			{
				i = 4;
				c = line[4];
				write(1, "\n", 1);
				write(1, &c, 1);
				i++;
			}
			else
				return (0);
		}
//		if (ft_strchr(buf, '|'))
//			get_next_line(0, &line);
//		a = lexer(buf);
//		if(a = -1)
//		{
//			prinf("syntax err";)
//			continue;
//		}
//		good_line(buf);
		ft_printf("%s\n", line);
	}
	return (0);
}
