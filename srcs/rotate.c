/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:02:20 by ale-coss          #+#    #+#             */
/*   Updated: 2025/07/09 17:15:00 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **lst, bool print)
{
	t_node	*first;
	t_node	*second;

	if (!lst || !*lst)
		return ;
	first = *lst;
	second = (*lst)->next;
	*lst = second;
	first->next = NULL;
	ft_lstadd_back(lst, first);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_node **lst, bool print)
{
	t_node	*first;
	t_node	*second;

	if (!lst || !*lst)
		return ;
	first = *lst;
	second = (*lst)->next;
	*lst = second;
	first->next = NULL;
	ft_lstadd_back(lst, first);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b, bool print)
{
	ra(a, false);
	rb(b, false);
	if (print)
		ft_printf("rr\n");
}

void	double_rotate(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, true);
	set_position(*a);
	set_position(*b);
}
