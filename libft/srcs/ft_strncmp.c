/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanivia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:51:42 by fanivia           #+#    #+#             */
/*   Updated: 2021/01/05 16:51:45 by fanivia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str_1;
	unsigned char	*str_2;

	str_1 = (unsigned char *)s1;
	str_2 = (unsigned char *)s2;
	if (str_1 == str_2 || n == 0)
		return (0);
	while ((int)n >= 0 && *str_1 != '\0' && *str_2 != '\0')
	{
		if (n == 1 && (*str_1 - *str_2) == 0)
			return (0);
		if ((*str_1 - *str_2) == 0 && n > 0)
		{
			str_1++;
			str_2++;
		}
		else
			return (*str_1 - *str_2);
		n--;
	}
	return (*str_1 - *str_2);
}
