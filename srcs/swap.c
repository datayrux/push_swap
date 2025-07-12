/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:08:10 by ale-coss          #+#    #+#             */
/*   Updated: 2025/07/09 17:14:50 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **lst, bool print)
{
	t_node	*first;
	t_node	*second;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	first = *lst;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
	if (print)
		ft_printf("sa\n");
}

void	sb(t_node **lst, bool print)
{
	t_node	*first;
	t_node	*second;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	first = *lst;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
	if (print)
		ft_printf("sb\n");
}

void	ss(t_node **a, t_node **b, bool print)
{
	sa(a, false);
	sb(b, false);
	if (print)
		ft_printf("ss\n");
}
