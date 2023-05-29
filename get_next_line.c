/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jborner <jborner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:52:01 by jborner           #+#    #+#             */
/*   Updated: 2023/05/29 19:21:45 by jborner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	null_cases(ssize_t bytes_read, char *str)
{
	if (bytes_read == -1)
		return (1);
	if (bytes_read == 0 && str == NULL)
		return (1);
	return (0);
}

char	*read_data(int fd, char *buffer, char *str, int *j)
{
	ssize_t	bytes_read;
	int		i;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (null_cases(bytes_read, str))
		return (NULL);
	while (bytes_read > 0)
	{
		i = 0;
		while (buffer[i] != '\0')
		{
			str = (char *)ft_my_realloc(str, (*j + 2) * sizeof(char));
			if (!str)
				return (NULL);
			str[(*j)++] = buffer[i];
			if (buffer[i] == '\n')
			{
				str[*j] = '\0';
				buffer = ft_memmove(buffer, buffer + i + 1, (bytes_read - i));
				buffer[bytes_read - i - 1] = '\0';
				return (str);
			}
			i++;
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	str[*j] = '\0';
	return (str);
}

char	*str_next_line(int fd, char *buffer, char *str, int *j)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		str = (char *)ft_my_realloc(str, (*j + 2) * sizeof(char));
		if (!str)
			return (NULL);
		str[*j] = buffer[i];
		(*j)++;
		if (buffer[i] == '\n')
		{
			str[*j] = '\0';
			buffer = ft_memmove(buffer, &buffer[i] + 1, (BUFFER_SIZE - i - 1));
			buffer[BUFFER_SIZE - 1] = '\0';
			return (str);
		}
		i++;
	}
	return (read_data(fd, buffer, str, j));
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;
	int			j;

	if (fd < 0)
		return (NULL);
	j = 0;
	str = NULL;
	str = str_next_line(fd, buffer, str, &j);
	return (str);
}

/* #include <stdio.h>

int	main(void)
{
	int fd;
	char *str;

	fd = open("hello.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}

	str = get_next_line(fd);
	printf("next line: %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("next line: %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("next line: %s\n", str);
	free(str);
 	str = get_next_line(fd);
	printf("next line: %s\n", str);
	free(str); 
	str = get_next_line(fd);
	printf("next line: %s\n", str);
	free(str); 
	close(fd);
	return (0);
}  */