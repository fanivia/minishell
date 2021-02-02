/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanivia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 19:25:06 by fanivia           #+#    #+#             */
/*   Updated: 2021/01/08 19:25:08 by fanivia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str_1;
	size_t	i;

	str_1 = (char *)s1;
	str_1 = (char *)malloc((ft_strlen(str_1) + 1) * sizeof(char));
	if (str_1)
	{
		i = 0;
		while (s1[i])
		{
			str_1[i] = s1[i];
			i++;
		}
		str_1[i] = '\0';
		return ((char *)str_1);
	}
	else
		return (NULL);
}
