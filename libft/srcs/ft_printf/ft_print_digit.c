/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanivia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 19:49:21 by fanivia           #+#    #+#             */
/*   Updated: 2020/08/02 19:50:43 by fanivia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		d_minus(t_in *in, int spec, int intlen)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (spec < 0)
	{
		in->w_o += write(1, "-", 1);
		i++;
	}
	while (((in->acc - j++) - intlen) > 0)
	{
		in->w_o += write(1, "0", 1);
		i++;
	}
	if (in->flags[5] > 0 && in->acc == 0 && spec == 0)
		intlen = 0;
	ft_putd(in, spec, intlen);
	in->width = (in->width - i) - intlen;
	while (in->width-- > 0)
		in->w_o += write(1, " ", 1);
}

void		d_acc(t_in *in, int spec, int intlen)
{
	int	i;
	int j;

	i = intlen;
	j = 0;
	if (spec < 0)
		i++;
	if (in->acc > intlen)
		i = (i - intlen) + in->acc;
	if (in->acc == 0 && spec == 0)
		i = 0;
	while ((in->width-- - i) > 0)
		in->w_o += write(1, " ", 1);
	if (spec < 0)
		in->w_o += write(1, "-", 1);
	while (in->acc - j++ > intlen)
		in->w_o += write(1, "0", 1);
	if (in->acc == 0 && spec == 0)
		return ;
	else
		ft_putd(in, spec, intlen);
}

void		d_zero(t_in *in, int spec, int intlen)
{
	int i;

	i = intlen;
	if (spec < 0)
	{
		in->w_o += write(1, "-", 1);
		i++;
	}
	while (in->width-- - i > 0)
		in->w_o += write(1, "0", 1);
	ft_putd(in, spec, intlen);
}

void		d_default(t_in *in, int spec, int intlen)
{
	int	sign;

	sign = 0;
	if (spec < 0)
		sign++;
	while ((in->width-- - intlen) - sign > 0)
		in->w_o += write(1, " ", 1);
	if (spec < 0)
		in->w_o += write(1, "-", 1);
	ft_putd(in, spec, intlen);
}

void		print_d(t_in *in, va_list args)
{
	int		spec;
	int		copy;
	int		intlen;

	spec = (int)va_arg(args, int);
	intlen = 1;
	copy = spec;
	while ((copy = (copy / 10)) != 0)
		intlen++;
	if (in->flags[0] > 0)
		d_minus(in, spec, intlen);
	else if (in->flags[5] > 0)
		d_acc(in, spec, intlen);
	else if (in->flags[1] > 0)
		d_zero(in, spec, intlen);
	else
		d_default(in, spec, intlen);
}
