/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:55:09 by ale-coss          #+#    #+#             */
/*   Updated: 2025/07/07 18:03:19 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	node_cmp(t_node *list)
{
	t_node	*tmp;

	while (list)
	{
		tmp = list->next;
		while (tmp)
		{
			if (list->nb == tmp->nb)
				return (1);
			tmp = tmp->next;
		}
		list = list->next;
	}
	return (0);
}

int	ft_atol(const char *str, int *p)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
		if (((nb * sign) > INT_MAX) || (nb * sign < INT_MIN))
			return (0);
	}
	nb = nb * sign;
	*p = nb;
	return (1);
}

void	write_free_exit(t_node *list)
{
	write(2, "Error\n", 6);
	ft_free_list(&list);
	exit(1);
}

void	ft_free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
