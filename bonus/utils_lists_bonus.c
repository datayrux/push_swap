/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:38:33 by ale-coss          #+#    #+#             */
/*   Updated: 2025/07/12 13:02:17 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_node	*lst_new(int nb)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	ft_bzero(new, sizeof(*new));
	new->nb = nb;
	return (new);
}

void	ft_free_list(t_node **lst)
{
	t_node	*to_free;
	t_node	*temp;

	temp = *lst;
	while (temp)
	{
		to_free = temp;
		temp = temp->next;
		free(to_free);
	}
	*lst = NULL;
}

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_node **lst, t_node *new_node)
{
	t_node	*last;

	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new_node;
	new_node->prev = last;
}

int	ft_size_list(t_node *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
