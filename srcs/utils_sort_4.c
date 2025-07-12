/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:20:53 by ale-coss          #+#    #+#             */
/*   Updated: 2025/07/12 13:07:13 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_on_top(t_node **a)
{
	while ((*a)->nb != find_node_min(*a)->nb)
	{
		if (find_node_min(*a)->above_median)
			ra(a, true);
		else
			rra(a, true);
	}
}

t_node	*get_cheapest(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->cheapest)
		{
			lst->cheapest = false;
			return (lst);
		}
		lst = lst->next;
	}
	return (NULL);
}
