/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:50:55 by ale-coss          #+#    #+#             */
/*   Updated: 2025/07/09 16:19:04 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	valid_nb(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		++i;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	all_valid_nb(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (!valid_nb(tab[i]))
			return (0);
		i++;
	}
	return (1);
}

t_node	*create_list(char **tab)
{
	int		i;
	int		val;
	t_node	*first;
	t_node	*new_node;

	i = 0;
	val = 0;
	first = NULL;
	while (tab[i])
	{		
		if (!ft_atol(tab[i], &val))
		{
			ft_free_list(&first);
			return (NULL);
		}
		new_node = lst_new(val);
		if (!new_node)
		{
			ft_free_list(&first);
			return (NULL);
		}
		ft_lstadd_back(&first, new_node);
		i++;
	}
	return (first);
}

int	pars(int ac, char **av, t_stack stack[2])
{
	char	**tab;

	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		if (!tab || !*tab)
			return (write(2, "Error\n", 6), 0);
	}
	else
		tab = &av[1];
	if (!all_valid_nb(tab))
	{
		if (ac == 2)
			ft_free_split(tab);
		return (write(2, "Error\n", 6), 0);
	}
	stack[a].head = create_list(tab);
	if (ac == 2)
		ft_free_split(tab);
	if (!stack[a].head || node_cmp(stack[a].head))
		write_free_exit(stack[a].head);
	return (1);
}

// void	print_list(t_node *list)
// {
// 	while (list)
// 	{
// 		ft_printf("%d\n", list->nb);
// 		// printf("%d\n", list->idx);
// 		list = list->next;
// 	}
// }
