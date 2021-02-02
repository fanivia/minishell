/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanivia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 19:51:06 by fanivia           #+#    #+#             */
/*   Updated: 2020/08/02 19:52:32 by fanivia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	check_flags(t_in *in)
{
	if (in->flags[0] > 0)
		in->flags[1] = 0;
	if (in->width < 0)
	{
		in->width = -in->width;
		in->flags[0]++;
	}
	if (in->acc < 0)
		in->flags[5] = 0;
}

void	put_hex(t_in *in, unsigned int spec, int intlen)
{
	int		i;
	char	s[intlen];

	if (intlen == 0)
		return ;
	i = intlen - 1;
	while (i >= 0)
	{
		s[i] = "0123456789abcdef"[spec % 16];
		spec /= 16;
		i--;
	}
	i = 0;
	while (i < intlen)
	{
		if (in->spec == 'X' && s[i] >= 'a' && s[i] <= 'f')
			s[i] -= 32;
		in->w_o += write(1, &s[i], 1);
		i++;
	}
}

void	hex_acc(t_in *in, unsigned int spec, int intlen)
{
	int	i;
	int j;

	i = intlen;
	j = 0;
	if (in->acc > intlen)
		i = in->acc;
	if (in->acc == 0 && spec == 0)
		i = 0;
	while ((in->width-- - i) > 0)
		in->w_o += write(1, " ", 1);
	while (in->acc - j++ > intlen)
		in->w_o += write(1, "0", 1);
	if (in->acc == 0 && spec == 0)
		return ;
	else
		put_hex(in, spec, intlen);
}

void	hex_minus(t_in *in, unsigned int spec, int intlen)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((in->acc - j++) - intlen > 0)
	{
		in->w_o += write(1, "0", 1);
		i++;
	}
	if (in->flags[5] > 0 && in->acc == 0 && spec == 0)
		intlen = 0;
	put_hex(in, spec, intlen);
	while ((in->width-- - i) - intlen > 0)
		in->w_o += write(1, " ", 1);
}

void	print_hex(t_in *in, va_list args)
{
	unsigned int		spec;
	unsigned int		copy;
	int					intlen;
	char				space;

	spec = (unsigned int)va_arg(args, unsigned int);
	copy = spec;
	intlen = 1;
	space = ' ';
	while ((copy = (copy / 16)) != 0)
		intlen++;
	if (in->flags[0] > 0)
		hex_minus(in, spec, intlen);
	else if (in->flags[5] > 0)
		hex_acc(in, spec, intlen);
	else
	{
		if (in->flags[1] > 0)
			space = '0';
		while ((in->width-- - intlen) > 0)
			in->w_o += write(1, &space, 1);
		put_hex(in, spec, intlen);
	}
}
