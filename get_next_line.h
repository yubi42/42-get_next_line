/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jborner <jborner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:53:02 by jborner           #+#    #+#             */
/*   Updated: 2023/05/31 13:49:18 by jborner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*read_data(int fd, char *buffer, char *str, int *j);
char	*file_end(int bytes_read, int *j, char *str, char *buffer);
char	*str_next_line(int fd, char *buffer, char *str, int *j);
char	*get_next_line(int fd);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_my_realloc(void *str, size_t size);
size_t	ft_strlen(const char *s);

#endif
