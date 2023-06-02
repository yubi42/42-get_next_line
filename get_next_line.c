/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jborner <jborner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:52:01 by jborner           #+#    #+#             */
/*   Updated: 2023/06/02 16:11:48 by jborner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*file_end(int bytes_read, int *j, char *str, char *buffer)
{
	if (bytes_read == 0 && str == NULL)
		return (NULL);
	if (bytes_read < 0)
	{
		free(str);
		return (NULL);
	}
	str[*j] = '\0';
	buffer[0] = '\0';
	return (str);
}

char	*read_data(int fd, char *buffer, char *str, int *j)
{
	ssize_t	bytes_read;
	int		i;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (file_end(bytes_read, j, str, buffer));
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
	while (buffer[--i])
		buffer[i] = '\0';
	return (read_data(fd, buffer, str, j));
}

char	*str_next_line(int fd, char *buffer, char *str, int *j)
{
	int	i;
	int	count_buf;

	count_buf = ft_strlen(buffer);
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
			buffer = ft_memmove(buffer, &buffer[i] + 1, (count_buf - i));
			buffer[count_buf] = '\0';
			return (str);
		}
		i++;
	}
	while (buffer[--i])
		buffer[i] = '\0';
	return (read_data(fd, buffer, str, j));
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;
	int			j;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	j = 0;
	str = NULL;
	str = str_next_line(fd, buffer, str, &j);
	return (str);
}
