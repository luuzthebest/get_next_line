/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounajar <hounajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:06:12 by hounajar          #+#    #+#             */
/*   Updated: 2025/01/05 21:39:40 by hounajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int size_cal(char *buff)
{
	// printf("entred size cal func\n");
	int i;

	i = 0;
	while (*buff && *buff != '\n')
	{
		i++;
		buff++;
	}
	if (*buff == '\n')
	{
		i++;
		buff++;
	}
	return (i);
}
char *extract_line(char *buff)
{
	// printf("entred extract line\n");
	int i;
	char *line;

	line = malloc(size_cal(buff) + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (*buff && *buff != '\n')
	{
		line[i] = *buff;
		i++;
		buff++;
	}
	if (*buff == '\n')
		line[i] = '\n';
	return line;
}

char *get_next_line(int fd)
{
	// printf("entred get next line func\n");
	static char *buff;
	char *line;
	
	if (!buff) // check if buff already exists (eg: 2nd call..)
	{
		buff = malloc(BUFFER_SIZE); // handle int max or int min need
		if (!buff || fd < 0)
			return (NULL);
		read(fd, buff, BUFFER_SIZE);
	}
	// printf("entering extract line func\n");
	line = extract_line(buff);
	printf("-----------------buff-----------\n%s\n", buff);
	buff += size_cal(buff);
	return line;
}
int main()
{
	int fd = open("text.txt", O_RDONLY);
	printf("1:\n%s" , get_next_line(fd));
	printf("2:\n%s" , get_next_line(fd));
	printf("3:\n%s" , get_next_line(fd));
}