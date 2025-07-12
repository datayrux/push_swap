/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:44:50 by ale-coss          #+#    #+#             */
/*   Updated: 2025/07/05 13:39:03 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*alloc;
	unsigned int	i;

	i = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	alloc = malloc(sizeof(char) * (len + 1));
	if (!alloc)
		return (NULL);
	while (i < len)
	{
		alloc[i] = s[start + i];
		i++;
	}
	alloc[i] = '\0';
	return (alloc);
}

unsigned int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *s = "petit";
// 	unsigned int start = 4;
// 	size_t len = 4;
// 	char *substr = ft_substr(s, start, len);

// 	printf("%s\n", substr);
// 	return (0);
// }
