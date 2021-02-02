/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ud.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanivia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 20:03:42 by fanivia           #+#    #+#             */
/*   Updated: 2020/08/02 20:14:41 by fanivia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_putd(t_in *in, int spec, int intlen)
{
	int		devisor;
	int		res;
	char	c;

	if (intlen < 1)
		return ;
	devisor = 1;
	while (intlen-- > 1)
		devisor *= 10;
	while (devisor > 0)
	{
		res = spec / devisor;
		if (res < 0)
			res = -res;
		c = res + '0';
		in->w_o += write(1, &c, 1);
		spec = spec % devisor;
		devisor /= 10;
	}
}

void	ft_putud(t_in *in, unsigned int spec, int intlen)
{
	int		devisor;
	char	c;

	if (intlen < 1)
		return ;
	devisor = 1;
	while (intlen-- > 1)
		devisor *= 10;
	while (devisor > 0)
	{
		c = (spec / devisor) + '0';
		in->w_o += write(1, &c, 1);
		spec = spec % devisor;
		devisor /= 10;
	}
}

void	ud_minus(t_in *in, unsigned int spec, int intlen)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (((in->acc - j++) - intlen) > 0)
	{
		in->w_o += write(1, "0", 1);
		i++;
	}
	if (in->flags[5] > 0 && in->acc == 0 && spec == 0)
		intlen = 0;
	ft_putud(in, spec, intlen);
	in->width = (in->width - i) - intlen;
	while (in->width-- > 0)
		in->w_o += write(1, " ", 1);
}

void	ud_acc(t_in *in, unsigned int spec, int intlen)
{
	int i;
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
		ft_putud(in, spec, intlen);
}

void	ft_print_ud(t_in *in, va_list args)
{
	unsigned int	spec;
	unsigned int	copy;
	int				intlen;
	char			space;

	spec = (unsigned int)va_arg(args, unsigned int);
	copy = spec;
	intlen = 1;
	space = ' ';
	while ((copy = (copy / 10)) != 0)
		intlen++;
	if (in->flags[0] > 0)
		ud_minus(in, spec, intlen);
	else if (in->flags[5] > 0)
		ud_acc(in, spec, intlen);
	else
	{
		if (in->flags[1] > 0)
			space = '0';
		while (in->width-- - intlen > 0)
			in->w_o += write(1, &space, 1);
		ft_putud(in, spec, intlen);
	}
}
