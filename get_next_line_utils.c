/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svarela <svarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:21:54 by svarela           #+#    #+#             */
/*   Updated: 2024/02/19 13:45:56 by svarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gnl_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*ft_gnl_strchr(const char *s, int c)
{
	char	str;

	str = c;
	while (*s)
	{
		if (*s == str)
		{
			return ((char *)s);
		}
		s++;
	}
	if (str == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_gnl_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	char	*result;
	size_t	len;

	len = ft_gnl_strlen(s1) + ft_gnl_strlen(s2);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = 0;
	return (result);
}

void	*ft_gnl_calloc(size_t num_elements, size_t element_size)
{
	void	*init_memory;
	size_t	i;

	init_memory = malloc(num_elements * element_size);
	if (!init_memory)
		return (NULL);
	i = 0;
	while (i < num_elements * element_size)
	{
		*((unsigned char *)(init_memory + i)) = (unsigned char)0;
		i++;
	}
	return (init_memory);
}

size_t	ft_gnl_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (src == NULL || dst == NULL)
		return (0);
	while (src[i] != '\0')
		i++;
	if (dstsize != 0)
	{
		while (len < (dstsize -1) && src[len] != '\0')
		{
			dst[len] = src[len];
			len++;
		}
	}
	dst[len] = '\0';
	return (i);
}
