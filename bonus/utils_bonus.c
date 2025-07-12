/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:29:01 by ale-coss          #+#    #+#             */
/*   Updated: 2025/07/09 17:26:46 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
		{
			if ((unsigned char) s1[i] > (unsigned char)s2[i])
				return (1);
			if ((unsigned char)s2[i] > (unsigned char)s1[i])
				return (-1);
		}
		i++;
	}
	return (0);
}

int	read_and_exec(char *line, t_node **a, t_node **b)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		return (sa(a), 1);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		return (sb(b), 1);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		return (ss(a, b), 1);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		return (pa(a, b), 1);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		return (pb(b, a), 1);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		return (ra(a), 1);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		return (rb(b), 1);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		return (rr(a, b), 1);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		return (rra(a), 1);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		return (rrb(b), 1);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		return (rrr(a, b), 1);
	else
		return (0);
}

int	check(t_node **a, t_node **b)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (read_and_exec(line, a, b))
			;
		else
		{
			write(2, "Error\n", 6);
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	return (1);
}

	// if (ft_strncmp(line, "sa\n", 3) == 0)
	// 	sa(a);
	// else if (ft_strncmp(line, "sb\n", 3) == 0)
	// 	sb(b);
	// else if (ft_strncmp(line, "ss\n", 3) == 0)
	// 	ss(a, b);
	// else if (ft_strncmp(line, "pa\n", 3) == 0)
	// 	pa(a, b);
	// else if (ft_strncmp(line, "pb\n", 3) == 0)
	// 	pb(b, a);
	// else if (ft_strncmp(line, "ra\n", 3) == 0)
	// 	ra(a);
	// else if (ft_strncmp(line, "rb\n", 3) == 0)
	// 	rb(b);
	// else if (ft_strncmp(line, "rr\n", 3) == 0)
	// 	rr(a, b);
	// else if (ft_strncmp(line, "rra\n", 4) == 0)
	// 	rra(a);
	// else if (ft_strncmp(line, "rrb\n", 4) == 0)
	// 	rrb(b);
	// else if (ft_strncmp(line, "rrr\n", 4) == 0)
	// 	rrr(a, b);
