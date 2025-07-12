/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:08:10 by ale-coss          #+#    #+#             */
/*   Updated: 2025/07/09 16:19:38 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_node **lst)
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
}

void	sb(t_node **lst)
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
}

void	ss(t_node **a, t_node **b)
{
	sa(a);
	sb(b);
}
