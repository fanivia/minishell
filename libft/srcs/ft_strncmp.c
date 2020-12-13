/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 04:37:54 by student           #+#    #+#             */
/*   Updated: 2020/06/03 23:36:53 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;
	int	c;
	int	ret;

	i = 0;
	if (n == 0)
		return (0);
	c = n - 1;
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0') && (i != c))
		i++;
	ret = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
	if (ret < 0)
		return (-1);
	if (ret == 0)
		return (0);
	return (1);
}
