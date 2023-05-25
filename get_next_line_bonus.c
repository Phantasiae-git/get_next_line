/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:11:42 by rfontes-          #+#    #+#             */
/*   Updated: 2023/04/18 21:47:04 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*string[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (0);
	string[fd] = readfile(string[fd], fd, -1);
	if (!string[fd])
		return (NULL);
	line = getlinefromstring(string[fd]);
	string[fd] = advancestring(string[fd]);
	return (line);
}
