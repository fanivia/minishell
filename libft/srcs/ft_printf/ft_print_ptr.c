/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanivia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 19:53:14 by fanivia           #+#    #+#             */
/*   Updated: 2020/08/02 19:56:27 by fanivia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	clean_info(t_in *in)
{
	int i;

	i = 0;
	in->acc = 0;
	in->width = 0;
	in->spec = '0';
	in->size = '0';
	while (i < 6)
	{
		in->flags[i] = 0;
		i++;
	}
}

void	put_space(t_in *in, int j, size_t copy, char *s)
{
	int i;
	int k;

	i = 4;
	k = 0;
	if (in->flags[5] > 0 && in->acc == 0)
		j = 0;
	if (in->flags[0] == 0)
		while ((in->width-- - (j + 2) > 0))
			in->w_o += write(1, " ", 1);
	in->w_o += write(1, "0x", 2);
	while (((in->acc - k++) - j) > 0)
		in->w_o += write(1, "0", 1);
	while (i < 16 && s[i] == '0')
		i++;
	if ((copy == 0 && in->acc > 0) || (copy == 0 && in->flags[5] == 0))
		in->w_o += write(1, "0", 1);
	else
		while (s[i] != '\0')
			in->w_o += write(1, &s[i++], 1);
	if (in->flags[0] > 0)
		while ((in->width-- - (j + 2)) > 0)
			in->w_o += write(1, " ", 1);
}

void	put_pointer(t_in *in, size_t spec)
{
	size_t	i;
	char	s[2 * sizeof(spec) + 1];
	int		j;
	size_t	copy;

	copy = spec;
	s[2 * sizeof(spec)] = '\0';
	i = 2 * sizeof(spec) - 1;
	j = 0;
	while (i != 0)
	{
		s[i] = "0123456789abcdef"[spec & 0x0f];
		spec >>= 4;
		i--;
	}
	s[0] = "0123456789abcdef"[spec & 0x0f];
	i = 4;
	while (s[i] != '\0' && s[i] == '0')
		i++;
	while (s[i++] != '\0')
		j++;
	i = 4;
	if (copy == 0)
		j = 1;
	put_space(in, j, copy, s);
}

void	ft_print_ptr(t_in *in, va_list args)
{
	size_t	spec;

	spec = (size_t)va_arg(args, size_t);
	put_pointer(in, spec);
}
