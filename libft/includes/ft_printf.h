/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanivia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 19:57:19 by fanivia           #+#    #+#             */
/*   Updated: 2020/08/02 20:37:14 by fanivia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_in
{
	int		flags[6];
	int		width;
	int		acc;
	char	size;
	char	spec;
	int		w_m;
	int		id;
	int		w_o;
}				t_in;

int				ft_printf(const char *fmt, ...);
t_in			*ft_infonew(void);
void			print_spec(const char *fmt, t_in *in, va_list args);
int				fill_info(t_in *in, const char *fmt, va_list args);
void			print_d(t_in *in, va_list args);
void			d_acc(t_in *in, int spec, int intlen);
void			d_minus(t_in *in, int spec, int intlen);
void			d_zero(t_in *in, int spec, int intlen);
void			d_default(t_in *in, int spec, int intlen);
void			ft_putd(t_in *in, int spec, int i);
int				ft_num(t_in *in, const char *fmt);
void			ft_print_char(t_in *in, va_list args);
void			print_s(t_in *in, va_list args);
void			s_minus(t_in *in, char *spec);
void			ft_print_ptr(t_in *in, va_list args);
void			put_pointer(t_in *in, size_t spec);
void			put_space(t_in *in, int j, size_t copy, char *s);
void			print_hex(t_in *in, va_list args);
void			hex_minus(t_in *in, unsigned int spec, int intlen);
void			hex_acc(t_in *in, unsigned int spec, int intlen);
void			put_hex(t_in *in, unsigned int spec, int intlen);
void			ft_print_ud(t_in *in, va_list args);
void			ud_acc(t_in *in, unsigned int spec, int intlen);
void			ud_minus(t_in *in, unsigned int spec, int intlen);
void			ft_putud(t_in *in, unsigned int spec, int intlen);
void			clean_info(t_in *in);
void			check_flags(t_in *in);

#endif
