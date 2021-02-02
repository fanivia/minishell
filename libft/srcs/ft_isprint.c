/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanivia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:17:54 by fanivia           #+#    #+#             */
/*   Updated: 2021/01/02 18:17:56 by fanivia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	if ((ch >= 040 && ch <= 077) || (ch >= 0100 && ch <= 0176))
		return (1);
	else
		return (0);
}
