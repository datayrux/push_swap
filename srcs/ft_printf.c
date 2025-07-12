/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:52:33 by ale-coss          #+#    #+#             */
/*   Updated: 2025/07/02 17:35:21 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_switch(const char format, va_list args, int *ret_val)
{
	if (format == 'c')
		ft_write(va_arg(args, int), ret_val);
	else if (format == 's')
		ft_putstr(va_arg(args, char *), ret_val);
	else if (format == 'p')
		ft_putptr(va_arg(args, unsigned long), ret_val);
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), ret_val);
	else if (format == 'u')
		ft_putnbru(va_arg(args, unsigned int), ret_val);
	else if (format == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), FT_HEX_LOW, ret_val);
	else if (format == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), FT_HEX_UP, ret_val);
	else if (format == '%')
		ft_write('%', ret_val);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret_val;

	ret_val = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_switch(*format, args, &ret_val);
		}
		else
			ft_write(*format, &ret_val);
		++format;
	}
	va_end(args);
	return (ret_val);
}
