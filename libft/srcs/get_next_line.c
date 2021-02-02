/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanivia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 04:08:42 by fanivia           #+#    #+#             */
/*   Updated: 2020/07/30 00:13:18 by fanivia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_remainder_handl(char **str, char **line, char *tmp)
{
	char	*temp;

	*tmp++ = '\0';
	*line = ft_strdup(*str);
	if (*tmp == '\0')
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	temp = ft_strdup(tmp);
	free(*str);
	*str = temp;
	return (1);
}

static int	ft_remainder(char **str, char **line)
{
	char *tmp;

	if (*str)
	{
		if ((tmp = ft_strchr(*str, '\n')))
			return (ft_remainder_handl(str, line, tmp));
		*line = *str;
		*str = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*str[MAX_OPEN_FILES];
	char		*tmp;
	char		buf[BUFFER_SIZE + 1];
	int			byte_was_read;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if ((read(fd, buf, 0)) < 0)
		return (-1);
	while ((byte_was_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[byte_was_read] = '\0';
		str[fd] = ft_strjoin(str[fd], buf);
		if ((tmp = ft_strchr(str[fd], '\n')))
			return (ft_remainder_handl(&str[fd], line, tmp));
	}
	if (byte_was_read < 0)
		return (-1);
	return (ft_remainder(&str[fd], line));
}
