/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanivia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 01:00:43 by fanivia           #+#    #+#             */
/*   Updated: 2020/11/28 01:00:49 by fanivia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str_1, const char *str_2)
{
	int	i;
	int	ret;

	if (!str_1 || !str_2)
		return (0);
	i = 0;
	while (str_1[i] == str_2[i] && (str_1[i] != '\0') && (str_2[i] != '\0'))
		i++;
	ret = ((unsigned char *)str_1)[i] - ((unsigned char *)str_2)[i];
	if (ret < 0)
		return (-1);
	if (ret == 0)
		return (0);
	return (1);
}
