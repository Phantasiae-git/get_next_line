/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:11:58 by rfontes-          #+#    #+#             */
/*   Updated: 2023/05/15 12:34:53 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*string;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (0);
	string = readfile(string, fd, -1);
	if (!string)
		return (NULL);
	line = getlinefromstring(string);
	string = advancestring(string);
	return (line);
}

/*int	main(void)
{
int		fd1;
char	*line;
fd1 = open("empty.txt", O_RDONLY);
line = get_next_line(fd1);
printf("first line: |%s|", line);
line = get_next_line(fd1);
printf("second line: |%s|", line);
line = get_next_line(fd1);
printf("third line: %s", line);
line = get_next_line(fd1);
printf("fourth line: %s", line);
close(fd1);
}*/
