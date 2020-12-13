/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 19:10:22 by student           #+#    #+#             */
/*   Updated: 2020/06/03 23:31:50 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i_s1;
	size_t	i_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i_s2 = ft_strlen(s2) + ft_strlen(s1);
	if (!(newstr = (char*)malloc(sizeof(char) * (i_s2 + 1))))
		return (NULL);
	i_s1 = 0;
	i_s2 = 0;
	while (s1[i_s1] != '\0')
	{
		newstr[i_s1] = s1[i_s1];
		i_s1++;
	}
	while (s2[i_s2] != '\0')
		newstr[i_s1++] = s2[i_s2++];
	newstr[i_s1] = '\0';
	return (newstr);
}
