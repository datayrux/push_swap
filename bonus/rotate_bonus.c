/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:02:20 by ale-coss          #+#    #+#             */
/*   Updated: 2025/07/09 16:19:26 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_node **lst)
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
}

void	rb(t_node **lst)
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
}

void	rr(t_node **a, t_node **b)
{
	ra(a);
	rb(b);
}
