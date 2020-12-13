/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanivia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 04:52:42 by fanivia           #+#    #+#             */
/*   Updated: 2020/07/30 01:19:21 by fanivia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

# define SUCCESS 1
# define FINISH 0
# define ERROR -1

# include "libft.h"
# define MAX_OPEN_FILES 256

int		get_next_line(int fd, char **line);

#endif
