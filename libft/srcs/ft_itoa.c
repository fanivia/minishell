/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 22:46:11 by student           #+#    #+#             */
/*   Updated: 2020/06/04 00:40:43 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_whatcharsize(long n)
{
	int i;

	i = 0;
	if (n == 0)
	{
		i = 1;
		return (i);
	}
	if (n < 0)
		i = 1;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	size_t			size;
	char			*str;
	long long int	n2;

	n2 = n;
	size = ft_whatcharsize(n2);
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	if (n2 < 0)
	{
		str[0] = '-';
		n2 = n2 * (-1);
	}
	str[size] = '\0';
	if (n2 == 0)
		str[0] = '0';
	while ((size--) && (n2 > 0))
	{
		str[size] = (n2 % 10) + 48;
		n2 = n2 / 10;
	}
	return (str);
}
