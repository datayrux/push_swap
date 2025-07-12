/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:51:49 by ale-coss          #+#    #+#             */
/*   Updated: 2025/07/09 16:26:14 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_sorted(t_node *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		if (lst->nb > lst->next->nb)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	set_position(t_node *lst)
{
	int	i;
	int	median;

	i = 0;
	median = ft_size_list(lst) / 2;
	if (!lst)
		return ;
	while (lst)
	{
		lst->position = i;
		if (i <= median)
			lst->above_median = true;
		else
			lst->above_median = false;
		lst = lst->next;
		i++;
	}
}
