/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelmittelbach <manuelmittelbach@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:31:18 by mmittelb          #+#    #+#             */
/*   Updated: 2026/03/25 16:18:32 by manuelmitte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_end_of_line_check(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

char	*ft_one_line(char **str)
{
	int		i;
	char	*substring;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	substring = ft_substr(*str, 0, i);
	return (substring);
}

char	*ft_remain(char **str)
{
	int		i;
	char	*substring;
	int		strlen;

	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	strlen = ft_strlen(*str);
	substring = ft_substr(*str, i + 1, strlen);
	free(*str);
	return (substring);
}

char	*get_next_line2(char **remain)
{
	char	*line;

	line = ft_one_line(remain);
	if (!line)
		return (free(*remain), NULL);
	*remain = ft_remain(remain);
	if (!*remain)
		return (free(line), free(*remain), NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*remain[OPEN_MAX];
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	bytes_read = 1;
	while (ft_end_of_line_check(remain[fd]) == 0 && bytes_read != 0)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_free_remain(&remain[fd]), free(buffer), NULL);
		buffer[bytes_read] = '\0';
		if (bytes_read == 0 && (remain[fd] == NULL || *(remain[fd]) == '\0'))
			return (ft_free_remain(&remain[fd]), free(buffer), NULL);
		remain[fd] = ft_strjoin(remain[fd], buffer);
		if (!remain[fd])
			return (NULL);
	}
	return (get_next_line2(&remain[fd]));
}
