/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanivia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 18:57:45 by fanivia           #+#    #+#             */
/*   Updated: 2020/08/02 20:39:31 by fanivia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_num(t_in *in, const char *fmt)
{
	int	res;
	int	j;

	res = 0;
	j = 0;
	while (fmt[in->w_m + in->id + j] >= '0' && fmt[in->w_m + in->id + j] <= '9')
	{
		res = (res * 10) + fmt[in->w_m + in->id + j] - '0';
		j++;
	}
	if (in->flags[5] == 0)
		in->width = res;
	else
		in->acc = res;
	return (j);
}

int		fill_info(t_in *in, const char *fmt, va_list args)
{
	char	*flags;
	int		j;

	j = 0;
	flags = "-0# +.";
	if ((fmt[in->w_m + in->id] >= 'a' && fmt[in->w_m + in->id] <= 'z')
			|| fmt[in->w_m + in->id] == 'X' || fmt[in->w_m + in->id] == '%')
		in->spec = fmt[in->w_m + in->id];
	else if (fmt[in->w_m + in->id] == '*' && in->flags[5] == 0)
		in->width = va_arg(args, int);
	else if (fmt[in->w_m + in->id] == '*' && in->flags[5] > 0)
		in->acc = va_arg(args, int);
	else if (fmt[in->w_m + in->id] >= '1'
			&& fmt[in->w_m + in->id] <= '9')
		return (ft_num(in, fmt));
	else if (fmt[in->w_m + in->id] == '0' && in->flags[5] > 0)
		in->acc = 0;
	else
		while (flags[j])
		{
			if (fmt[in->w_m + in->id] == flags[j])
				in->flags[j]++;
			j++;
		}
	return (1);
}

void	print_spec(const char *fmt, t_in *in, va_list args)
{
	in->id++;
	while (in->spec == '0' && fmt[in->w_m + in->id] != '\0')
		in->id += fill_info(in, fmt, args);
	check_flags(in);
	if (in->spec == 'd' || in->spec == 'i')
		print_d(in, args);
	else if (in->spec == 'c' || in->spec == '%')
		ft_print_char(in, args);
	else if (in->spec == 's')
		print_s(in, args);
	else if (in->spec == 'p')
		ft_print_ptr(in, args);
	else if (in->spec == 'x' || in->spec == 'X')
		print_hex(in, args);
	else if (in->spec == 'u')
		ft_print_ud(in, args);
}

t_in	*ft_infonew(void)
{
	t_in	*in;
	int		i;

	i = 0;
	in = (t_in*)malloc(sizeof(t_in));
	if (in == NULL)
		return (NULL);
	in->acc = 0;
	in->width = 0;
	in->w_m = 0;
	in->id = 0;
	in->w_o = 0;
	while (i < 6)
	{
		in->flags[i] = 0;
		i++;
	}
	in->spec = '0';
	in->size = '0';
	return (in);
}

int		ft_printf(const char *fmt, ...)
{
	va_list	args;
	t_in	*in;
	int		res;

	if ((in = ft_infonew()) == NULL)
		return (-1);
	va_start(args, fmt);
	while (fmt[in->w_m + in->id] != '\0')
	{
		if (fmt[in->w_m + in->id] != '%')
			in->w_m += write(1, &fmt[in->w_m + in->id], 1);
		else if (fmt[in->w_m + in->id] == '%')
		{
			print_spec(fmt, in, args);
			clean_info(in);
		}
	}
	va_end(args);
	res = in->w_m + in->w_o;
	if (in != NULL)
		free(in);
	in = NULL;
	return (res);
}
