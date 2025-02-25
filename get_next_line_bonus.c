/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounajar <hounajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:06:12 by hounajar          #+#    #+#             */
/*   Updated: 2025/01/15 15:16:23 by hounajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	size_cal(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	return (i);
}

char	*extract_line(char *buff)
{
	int		i;
	char	*line;

	if (!buff || !*buff)
		return (NULL);
	line = malloc(size_cal(buff) + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_buff(char *buff)
{
	int		i;
	char	*new_buff;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	i++;
	new_buff = ft_strdup(&buff[i]);
	free(buff);
	return (new_buff);
}

char	*read_buff(int fd, char *buff)
{
	ssize_t	bytes_read;
	char	*line;

	bytes_read = 1;
	line = malloc((size_t)BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	while (bytes_read > 0 && !ft_strchr(buff, '\n'))
	{
		bytes_read = read(fd, line, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(line);
			free(buff);
			return (NULL);
		}
		line[bytes_read] = '\0';
		buff = ft_strjoin(buff, line);
	}
	free(line);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	buff[fd] = read_buff(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	line = extract_line(buff[fd]);
	buff[fd] = update_buff(buff[fd]);
	return (line);
}
