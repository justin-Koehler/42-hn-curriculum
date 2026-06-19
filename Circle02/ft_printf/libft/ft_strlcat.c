/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaurer <zmaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 19:18:08 by zmaurer           #+#    #+#             */
/*   Updated: 2026/05/24 12:32:51 by zmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	dest_length;
	size_t	src_length;
	size_t	i;

	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	if (dest_length >= destsize)
		return (destsize + src_length);
	i = 0;
	while (src[i])
	{
		if (dest_length + i >= destsize - 1)
			break ;
		dest[dest_length + i] = src[i];
		i++;
	}
	dest[dest_length + i] = '\0';
	return (dest_length + src_length);
}

// int	main(void)
// {
// 	char		buffer[20] = "Hello";
// 	const char	*src = " world";
// 	size_t		result;

// 	printf("Before:\n");
// 	printf("buffer = '%s'\n", buffer);
// 	printf("src    = '%s'\n\n", src);

// 	result = ft_strlcat(buffer, src, sizeof(buffer));

// 	printf("After ft_strlcat:\n");
// 	printf("buffer = '%s'\n", buffer);
// 	printf("returned length = %zu\n", result);

// 	return (0);
// }