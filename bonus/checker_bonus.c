/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:04:30 by ale-coss          #+#    #+#             */
/*   Updated: 2025/07/09 17:25:41 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_stack	stack[2];

	ft_bzero(stack, ((sizeof(t_stack)) * 2));
	if (ac > 1 && pars(ac, av, stack))
	{
		if (check(&stack[a].head, &stack[b].head))
		{
			if (is_sorted(stack[a].head) && !stack[b].head)
				ft_printf("OK\n");
			else
				ft_printf("KO\n");
		}
	}
	ft_free_list(&stack[a].head);
	ft_free_list(&stack[b].head);
	return (0);
}
