/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jborner <jborner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:52:48 by jborner           #+#    #+#             */
/*   Updated: 2023/05/31 13:49:37 by jborner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pdest;
	const unsigned char	*psrc;

	pdest = dest;
	psrc = src;
	if (dest == src)
		return (dest);
	if (dest < src)
		while (n-- > 0)
			*pdest++ = *psrc++;
	else
	{
		pdest += n - 1;
		psrc += n - 1;
		while (n--)
			*pdest-- = *psrc--;
	}
	return (dest);
}

void	*ft_my_realloc(void *str, size_t size)
{
	void	*new_str;

	new_str = malloc(size);
	if (!new_str)
		return (NULL);
	if (str != NULL)
	{
		ft_memmove(new_str, str, size - 2);
		free(str);
	}
	return (new_str);
}
