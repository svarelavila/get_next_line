/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svarela <svarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:26:04 by svarela           #+#    #+#             */
/*   Updated: 2024/02/19 17:33:43 by svarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*append_buffer(char *basin_buffer, char *read_buffer)
{
	char	*temp;

	temp = ft_gnl_strjoin(basin_buffer, read_buffer);
	if (basin_buffer)
	{
		free(basin_buffer);
	}
	return (temp);
}

char	*read_from_file(char *basin_buffer, int fd)
{
	char	*cup_buffer;
	int		bytes_read;

	cup_buffer = ft_gnl_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!cup_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(cup_buffer);
			free(basin_buffer);
			basin_buffer = NULL;
			return (NULL);
		}
		cup_buffer[bytes_read] = '\0';
		basin_buffer = append_buffer(basin_buffer, cup_buffer);
		if (ft_gnl_strchr(basin_buffer, '\n'))
			break ;
	}
	free (cup_buffer);
	return (basin_buffer);
}

char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = (char *)ft_gnl_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*obtain_rest(char *buffer)
{
	char	*end_line;
	size_t	rest_len;
	char	*rest;

	if (buffer == NULL)
		return (NULL);
	end_line = ft_gnl_strchr(buffer, '\n');
	if (end_line == NULL)
	{
		free(buffer);
		return (NULL);
	}
	rest_len = ft_gnl_strlen(end_line + 1);
	rest = ft_gnl_calloc(rest_len + 1, sizeof(char));
	if (rest == NULL)
	{
		free (buffer);
		return (NULL);
	}
	ft_gnl_strlcpy(rest, end_line + 1, rest_len + 1);
	free(buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*basin_buffer = NULL;
	char		*line;

	if (fd < 0 && read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!basin_buffer)
		basin_buffer = ft_gnl_calloc(1, sizeof(char));
	if (!ft_gnl_strchr(basin_buffer, '\n'))
		basin_buffer = read_from_file(basin_buffer, fd);
	if (!basin_buffer)
	{
		free(basin_buffer);
		basin_buffer = NULL;
		return (NULL);
	}
	line = extract_line(basin_buffer);
	basin_buffer = obtain_rest(basin_buffer);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open("texto4.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("\nError al abrir el archivo\n\n");
		return (1);
	}
	while (1)
	{
		printf("\n");
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		printf("line[%d]:%s\n", count, line);
		free(line);
		line = NULL;
	}
	close(fd);
	if (!line)
	printf("line[%d]:%s\n", count, line);
	//system ("leaks a.out");
	return (0);
}*/
