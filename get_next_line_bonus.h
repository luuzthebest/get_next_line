/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounajar <hounajar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:06:18 by hounajar          #+#    #+#             */
/*   Updated: 2025/01/12 23:57:11 by hounajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <unistd.h>
# include <string.h> 
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
int		ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif