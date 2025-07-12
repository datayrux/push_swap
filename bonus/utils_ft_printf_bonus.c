/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_printf_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:28:38 by ale-coss          #+#    #+#             */
/*   Updated: 2025/07/09 16:20:03 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_putnbr(int n, int *ret_val)
{
	if (n == FT_INT_MIN)
	{
		ft_putstr("-2147483648", ret_val);
		return ;
	}
	if (n < 0)
	{
		ft_write('-', ret_val);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10, ret_val);
	ft_write((n % 10 + '0'), ret_val);
}

void	ft_putnbru(unsigned int n, int *ret_val)
{
	if (n > 9)
		ft_putnbru(n / 10, ret_val);
	ft_write((n % 10 + '0'), ret_val);
}

void	ft_putnbr_base(unsigned long nbr, char *base, int *ret_val)
{
	char			base_nbr;
	unsigned int	len;

	len = 16;
	if (nbr >= len)
		ft_putnbr_base(nbr / len, base, ret_val);
	base_nbr = (base[nbr % len]);
	ft_write(base_nbr, ret_val);
}

void	ft_putptr(unsigned long p, int *ret_val)
{
	if (p == 0)
	{
		ft_putstr("(nil)", ret_val);
		return ;
	}
	else
	{
		ft_putstr("0x", ret_val);
		ft_putnbr_base(p, FT_HEX_LOW, ret_val);
	}
}
