/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:20:18 by ale-coss          #+#    #+#             */
/*   Updated: 2025/07/12 13:07:20 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_target_b(t_node *a, t_node *b)
{
	t_node	*current_a;
	t_node	*target_node;
	long	best_position_match;

	while (b)
	{
		best_position_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nb > b->nb && current_a->nb < best_position_match)
			{
				best_position_match = current_a->nb;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_position_match == LONG_MAX)
			b->target_node = find_node_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	cost_analyser(t_node *a, t_node *b)
{
	int	size_a;
	int	size_b;

	size_a = ft_size_list(a);
	size_b = ft_size_list(b);
	while (a)
	{
		a->push_cost = a->position;
		if (!(a->above_median))
			a->push_cost = size_a - (a->position);
		if (a->target_node->above_median)
			a->push_cost = (a->push_cost) + (a->target_node->position);
		else
			a->push_cost = (a->push_cost) + (size_b)
				- (a->target_node->position);
		a = a->next;
	}
}

void	set_cheapest(t_node *lst)
{
	long	cheapest_nb;
	t_node	*cheapest_node;

	cheapest_nb = LONG_MAX;
	if (!lst)
		return ;
	while (lst)
	{
		lst->cheapest = false;
		if (lst->push_cost < cheapest_nb)
		{	
			cheapest_nb = lst->push_cost;
			cheapest_node = lst;
		}
		lst = lst->next;
	}
	cheapest_node->cheapest = true;
}
