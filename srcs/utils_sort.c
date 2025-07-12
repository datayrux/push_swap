/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:51:49 by ale-coss          #+#    #+#             */
/*   Updated: 2025/07/07 18:06:19 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_node	*find_node_max(t_node *lst)
{
	long	max;
	t_node	*max_node;

	max = LONG_MIN;
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->nb > max)
		{
			max = lst->nb;
			max_node = lst;
		}
		lst = lst->next;
	}
	return (max_node);
}

t_node	*find_node_min(t_node *lst)
{
	long	min;
	t_node	*min_node;

	min = LONG_MAX;
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->nb < min)
		{
			min = lst->nb;
			min_node = lst;
		}
		lst = lst->next;
	}
	return (min_node);
}

void	sort_three_nodes(t_node **lst)
{
	t_node	*biggest_nb;

	biggest_nb = find_node_max(*lst);
	if (biggest_nb == *lst)
		ra(lst, true);
	else if ((*lst)->next == biggest_nb)
		rra(lst, true);
	if ((*lst)->nb > (*lst)->next->nb)
		sa(lst, true);
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
