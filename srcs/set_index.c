/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:04:10 by ale-coss          #+#    #+#             */
/*   Updated: 2025/07/07 18:13:03 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*set_idx_tab(t_node *lst, int size)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	while (lst)
	{
		tab[i++] = lst->nb;
		lst = lst->next;
	}
	return (tab);
}

int	*sort_idx_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	while (size > 0)
	{
		i = 0;
		while (i < (size - 1))
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
		size--;
	}
	return (tab);
}

void	set_idx(t_node *lst, int *tab, int size)
{
	int	i;

	while (lst)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i] == lst->nb)
			{
				lst->idx = i;
				break ;
			}
			i++;
		}
		lst = lst->next;
	}
}

void	indexation(t_node *lst, int size)
{
	int	*tab;

	tab = set_idx_tab(lst, size);
	sort_idx_tab(tab, size);
	set_idx(lst, tab, size);
	free(tab);
}
