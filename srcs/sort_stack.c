/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:59:45 by ale-coss          #+#    #+#             */
/*   Updated: 2025/07/07 17:54:46 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_node **a, t_node **b)
{
	int	size_a;
	int	nb_elems;

	size_a = ft_size_list(*a);
	nb_elems = size_a;
	indexation(*a, size_a);
	while (size_a > 3 && !(is_sorted(*a)))
	{
		pb(b, a, true);
		if ((*b)->idx > (nb_elems / 2))
			rb(b, true);
		size_a--;
	}
	sort_three_nodes(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	set_position(*a);
	min_on_top(a);
}

	// ft_printf("\n");
	// ft_printf("apres push_b des 2 premiers :\n\nstack a:\n");
	// print_list(*a);
	// ft_printf("\n");
	// ft_printf("stack b:\n");
	// print_list(*b);
	// ft_printf("\n");
		// if ((*b)->above_median)
		// init_nodes_a(*a, *b);

		// ft_printf("\n");
		// ft_printf("apres init_nodes_a :\n\nstack a:\n");
		// print_list(*a);
		// ft_printf("\n");
		// ft_printf("stack b:\n");
		// print_list(*b);
		// ft_printf("\n");

		// move_a_to_b(a, b);

		// ft_printf("\n");
		// ft_printf("apres move_a_to_b :\n\nstack a:\n");
		// print_list(*a);
		// ft_printf("\n");
		// ft_printf("stack b:\n");
		// print_list(*b);
		// ft_printf("\n");

	// ft_printf("\n");
	// ft_printf("apres tri des 3 premiers elements :\n\nstack a:\n");
	// print_list(*a);
	// ft_printf("\n");
	// ft_printf("stack b:\n");
	// print_list(*b);
	// ft_printf("\n");

		// ft_printf("\n");
		// ft_printf("apres init_nodes_b :\n\nstack a:\n");
		// print_list(*a);
		// ft_printf("\n");
		// ft_printf("stack b:\n");
		// print_list(*b);
		// ft_printf("\n");

		// ft_printf("\n");
		// ft_printf("apres move_b_to_a :\n\nstack a:\n");
		// print_list(*a);
		// ft_printf("\n");
		// ft_printf("stack b:\n");
		// print_list(*b);
		// ft_printf("\n");
	// current_index(*a);

	// ft_printf("\n");
	// ft_printf("apres min_on_top :\n\nstack a:\n");
	// print_list(*a);
	// ft_printf("\n");
