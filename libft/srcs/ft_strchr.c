/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 03:04:56 by student           #+#    #+#             */
/*   Updated: 2020/06/03 23:29:50 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s && (s[i] != (unsigned char)c) && (s[i] != '\0'))
		i++;
	if (s && s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (NULL);
}
