/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_printf_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:59:41 by ale-coss          #+#    #+#             */
/*   Updated: 2025/07/07 18:00:20 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *s, int *ret_val)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)", ret_val);
		return ;
	}
	while (s[i])
	{
		ft_write(s[i], ret_val);
		i++;
	}
}

void	ft_write(char c, int *ret_val)
{
	if (*ret_val != -1)
	{
		if (write(1, &c, 1) == 1)
			++*ret_val;
		else
			*ret_val = -1;
	}
}

// ici ++*ret_val --> on dereference ret_val puis on incremente la valeur 
// pointee par ret_val. 
// (utiliser *ret_val++ serait completement different, cela incremente le
// pointeur et non la valeur, donc le pointeur pointe a l'adresse suivante).
