/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounajar <hounajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:06:12 by hounajar          #+#    #+#             */
/*   Updated: 2025/01/09 15:43:13 by hounajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int size_cal(char *buff)
{
	// printf("entred size cal func\n");
	int i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	return (i);
}
char *extract_line(char *buff)
{
	// printf("entred extract line\n");
	int i;
	char *line;
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
	return line;
}

// char *get_next_line(int fd)
// {
// 	// printf("entred get next line func\n");
// 	static char *buff;
// 	static char *temp;
// 	char *line;
	
// 	if (!buff) // check if buff already allocated (eg: 2nd call..)
// 	{
// 		buff = malloc(BUFFER_SIZE); // handle int max or int min need
// 		if (!buff || fd < 0)
// 			return (NULL);
// 		read(fd, buff, BUFFER_SIZE);
// 		temp = buff;
// 	}
// 	// printf("entering extract line func\n");
// 	line = extract_line(buff);
// 	// printf("-----------------buff-----------\n%s\n", buff);
// 	if (!*buff)
// 	{
// 		free(temp);
// 		buff = NULL;
// 		return (NULL);
// 	}
// 	buff += size_cal(buff);
// 	return line;
// }
char *update_buff(char *buff)
{
	int i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	char *new_buff = ft_strdup(buff); // handle undefined behaviour here
	memmove(new_buff, &buff[i], i);
	free(buff);
	return (new_buff);
} 
char *get_next_line(int fd)
{
	static char *buff;
	char *line;
	
	if (!buff) // check if buff already allocated (eg: 2nd call..)
	{
		buff = malloc(BUFFER_SIZE); // handle int max or int min need
		if (!buff || fd < 0)
			return (NULL);
		if (read(fd, buff, BUFFER_SIZE) <= 0)
		{
			free(buff);
			buff = NULL;
			return (NULL);
		}
		
	}
	line = extract_line(buff);
	if (!line || !*buff)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	buff = update_buff(buff);
	return line;
}
int main()
{
	int fd = open("text.txt", O_RDONLY);
	char *res = get_next_line(fd);
	while (res)
	{
		printf("%s", res);
		free(res);
		res = get_next_line(fd);
	}
	// char *buff = "hello\nworld";
	// printf("%s", update_buff(buff));
}