/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:32:32 by ale-coss          #+#    #+#             */
/*   Updated: 2025/05/15 10:51:50 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define FT_HEX_UP "0123456789ABCDEF"
# define FT_HEX_LOW "0123456789abcdef"
# define FT_INT_MIN -2147483648
# define FT_INT_MAX 2147483647

int		ft_printf(const char *c, ...);
void	ft_write(char c, int *ret_val);
void	ft_putstr(char *s, int *ret_val);
void	ft_putnbr(int n, int *ret_val);
void	ft_putnbru(unsigned int n, int *ret_val);
void	ft_putptr(unsigned long p, int *ret_val);
void	ft_putnbr_base(unsigned long nbr, char *base, int *ret_val);

#endif
