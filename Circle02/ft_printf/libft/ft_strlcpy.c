/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaurer <zmaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 19:18:06 by zmaurer           #+#    #+#             */
/*   Updated: 2026/05/24 12:32:48 by zmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	src_length;

	src_length = 0;
	while (src[src_length])
		src_length++;
	if (destsize == 0)
		return (src_length);
	i = 0;
	while (src[i])
	{
		if (i >= destsize - 1)
			break ;
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_length);
}

// int	main(void)
// {
// 	char	dest[10];
// 	const char	*src = "Hello world";
// 	size_t		result;

// 	result = ft_strlcpy(dest, src, sizeof(dest));

// 	printf("src    : %s\n", src);
// 	printf("dest   : %s\n", dest);
// 	printf("return : %zu\n", result);

// 	return (0);
// }