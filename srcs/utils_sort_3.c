/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:25:53 by ale-coss          #+#    #+#             */
/*   Updated: 2025/07/10 15:56:18 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_nodes_b(t_node *a, t_node *b)
{
	set_position(b);
	set_position(a);
	best_target_b(a, b);
	cost_analyser(b, a);
	set_cheapest(b);
}

void	move_b_to_a(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = get_cheapest(*b);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		double_rotate(b, a, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		double_rrotate(b, a, cheapest_node);
	prep_for_push(b, cheapest_node, 'b');
	prep_for_push(a, cheapest_node->target_node, 'a');
	pa(a, b, true);
}

void	prep_for_push(t_node **lst, t_node *to_top_node, char stack_name)
{
	while (*lst != to_top_node)
	{
		if (stack_name == 'a')
		{
			if (to_top_node->above_median)
				ra(lst, true);
			else
				rra(lst, true);
		}
		if (stack_name == 'b')
		{
			if (to_top_node->above_median)
				rb(lst, true);
			else
				rrb(lst, true);
		}
	}
}
