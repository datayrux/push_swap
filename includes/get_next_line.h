/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 10:37:47 by ale-coss          #+#    #+#             */
/*   Updated: 2025/07/09 17:21:51 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

# if (BUFFER_SIZE <= 0)
#  error BUFFER_SIZE <= 0
# endif

# include <unistd.h>
# include <stdlib.h>

char			*get_next_line(int fd);
char			*get_a_line(char *remaining);
char			*update_remaining(char *remaining, char *line);
unsigned int	ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *src);
char			*ft_jonction(char *s1, char *s2);

#endif
