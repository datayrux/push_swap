/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:47:39 by ale-coss          #+#    #+#             */
/*   Updated: 2025/07/09 16:18:32 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_count_str(char const *str, char c)
{
	int	i;
	int	count;
	int	in_str;

	i = 0;
	count = 0;
	in_str = 0;
	while (str[i])
	{
		if (str[i] == c)
			in_str = 0;
		else if (str[i] != 0)
		{
			if (in_str == 0)
				count++;
			in_str = 1;
		}
		i++;
	}
	return (count);
}

void	*ft_protect(char **tab, size_t j)
{
	while (j > 0)
	{
		j--;
		free(tab[j]);
	}
	free(tab);
	return (0);
}

char	**ft_fill_tab(char const *s, char **tab, char c, size_t j)
{
	size_t	i;
	size_t	start;
	size_t	len;

	i = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c && ++i)
			len++;
		if (len > 0)
		{
			tab[j++] = ft_substr(s, start, len);
			if (!tab[j - 1])
				return (ft_protect(tab, j));
		}
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**tab;

	count = ft_count_str(s, c);
	tab = malloc(sizeof(char *) * (count + 1));
	if (!tab)
	{
		return (NULL);
	}
	tab = ft_fill_tab(s, tab, c, 0);
	return (tab);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*str = "ca ne marche jamais";
// 	// char	*str = "hello!aaaaaaaaaaa";
// 	char	c = 'a';
// 	char	**tab = ft_split(str, c);
// 	size_t	i = 0;

// 	while (tab[i])
// 	{
// 		printf("%s\n", tab[i]);
// 		free (tab[i]);
// 		i++;
// 	}
// 	free (tab);
// 	return (0);
// }
