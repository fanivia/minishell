/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanivia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 19:43:58 by fanivia           #+#    #+#             */
/*   Updated: 2020/08/02 19:48:31 by fanivia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_print_char(t_in *in, va_list args)
{
	unsigned char	spec;

	if (in->spec == '%')
		spec = '%';
	else
		spec = va_arg(args, int);
	if (in->flags[0] > 0)
		in->w_o += write(1, &spec, 1);
	while ((in->width-- - 1) > 0)
		if (in->flags[1] > 0)
			in->w_o += write(1, "0", 1);
		else
			in->w_o += write(1, " ", 1);
	if (in->flags[0] == 0)
		in->w_o += write(1, &spec, 1);
}

void	s_minus(t_in *in, char *spec)
{
	int	i;

	i = 0;
	if (in->flags[5] > 0)
	{
		while (in->acc-- > 0 && spec[i] != '\0')
		{
			in->w_o += write(1, &spec[i++], 1);
			in->width--;
		}
	}
	else
		while (spec[i] != '\0')
		{
			in->w_o += write(1, &spec[i++], 1);
			in->width--;
		}
	while (in->width-- > 0)
		in->w_o += write(1, " ", 1);
}

void	print_s(t_in *in, va_list args)
{
	char	*spec;
	int		i;
	int		len;

	if ((spec = va_arg(args, char*)) == NULL)
		spec = "(null)";
	i = 0;
	len = 0;
	if (in->flags[0] == 0)
	{
		while (spec[len] != '\0')
			len++;
		if (in->flags[5] > 0)
			if (len > in->acc)
				len = in->acc;
		while ((in->width-- - len) > 0)
			if (in->flags[1] > 0)
				in->w_o += write(1, "0", 1);
			else
				in->w_o += write(1, " ", 1);
		while (len-- > 0)
			in->w_o += write(1, &spec[i++], 1);
	}
	else if (in->flags[0] > 0)
		s_minus(in, spec);
}
