/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svarela <svarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:26:28 by svarela           #+#    #+#             */
/*   Updated: 2024/02/19 12:38:07 by svarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);
size_t	ft_gnl_strlen(const char *str);
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_strjoin(const char *s1, const char *s2);
void	*ft_gnl_calloc(size_t num_elements, size_t element_size);
size_t	ft_gnl_strlcpy(char *dst, const char *src, size_t dstsize);

#endif