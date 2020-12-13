/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 20:07:01 by student           #+#    #+#             */
/*   Updated: 2020/06/03 23:30:55 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	i;
	int				len;
	char			*str;

	i = 0;
	while (s[i] != '\0')
		i++;
	len = 1 + i;
	str = (char*)malloc(sizeof(char) * len);
	if (str)
	{
		i = 0;
		while (s[i] != '\0')
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
	}
	else
		return (NULL);
	return (str);
}
