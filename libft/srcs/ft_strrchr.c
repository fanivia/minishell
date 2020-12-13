/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 03:18:21 by student           #+#    #+#             */
/*   Updated: 2020/06/03 23:40:23 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			k = i;
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	if ((k != 0) || (s[0] == (unsigned char)c))
		return ((char *)s + k);
	return (NULL);
}
