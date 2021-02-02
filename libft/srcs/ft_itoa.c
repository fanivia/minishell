/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanivia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 20:45:40 by fanivia           #+#    #+#             */
/*   Updated: 2021/01/17 18:17:09 by fanivia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_of_int(int n)
{
	int size;

	size = 0;
	if (n == 0)
		return (size = 1);
	if (n < 0)
		size = 1;
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	size_t		size;
	char		*str;
	long int	num;

	num = n;
	size = ft_size_of_int((int)num);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = num * (-1);
	}
	if (num == 0)
		str[0] = '0';
	while (size > 0 && num > 0)
	{
		size--;
		str[size] = (char)((num % 10) + 48);
		num = num / 10;
	}
	return (str);
}
