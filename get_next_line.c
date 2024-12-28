/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounajar <hounajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:06:12 by hounajar          #+#    #+#             */
/*   Updated: 2024/12/26 13:24:50 by hounajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *extract_line(char *buff)
{
	int i;
	char *line;

	i = 0;
	while (*buff && *buff != '\n')
	{
		line[i] = *buff;
		i++;
		buff++;
	}
	if (*buff == '\n')
		line[i] == '\n';
	return line;
}

char *get_next_line(int fd)
{
	static char *buff;
	char *line;
 
	buff = malloc(BUFFER_SIZE); // handle int max or int min
	if (!buff || fd < 0)
		return (NULL);
	read(fd, buff, BUFFER_SIZE);

	line = extract_line(buff);
	
	return line;
}
int main()
{
	int fd = open("text.txt", O_RDONLY);
	printf("1: %s" , get_next_line(fd));
	// printf("2: %s" , get_next_line(fd));
}