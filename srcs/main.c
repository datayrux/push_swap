/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:04:30 by ale-coss          #+#    #+#             */
/*   Updated: 2025/07/10 17:08:32 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack[2];

	ft_bzero(stack, ((sizeof(t_stack)) * 2));
	if (ac > 1)
	{
		if (pars(ac, av, stack))
		{
			if (!(is_sorted(stack[a].head)))
			{
				if (ft_size_list(stack[a].head) == 2)
					sa(&stack[a].head, true);
				else if (ft_size_list(stack[a].head) == 3)
					sort_three_nodes(&stack[a].head);
				else
					sort_stack(&stack[a].head, &stack[b].head);
			}		
			ft_free_list(&stack[a].head);
			ft_free_list(&stack[b].head);
		}
		return (0);
	}
}
