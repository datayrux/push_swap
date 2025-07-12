/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:27:12 by ale-coss          #+#    #+#             */
/*   Updated: 2025/07/09 17:15:07 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **lst, bool print)
{
	t_node	*prev;
	t_node	*last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	prev = *lst;
	while (prev->next && prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *lst;
	*lst = last;
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_node **lst, bool print)
{
	t_node	*prev;
	t_node	*last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	prev = *lst;
	while (prev->next && prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *lst;
	*lst = last;
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b, bool print)
{
	rra(a, false);
	rrb(b, false);
	if (print)
		ft_printf("rrr\n");
}

void	double_rrotate(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, true);
	set_position(*a);
	set_position(*b);
}
