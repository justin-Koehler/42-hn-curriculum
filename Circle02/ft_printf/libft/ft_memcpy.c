/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaurer <zmaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 18:50:11 by zmaurer           #+#    #+#             */
/*   Updated: 2026/05/23 18:52:28 by zmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)

{
	size_t				i;
	unsigned char		*destination;
	const unsigned char	*source;

	i = 0;
	destination = dest;
	source = src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char	src[] = "Heya";
// 	char	dest[4];

// 	printf("Before memcpy:\n");
// 	printf("src  = %s\n", src);
// 	printf("dest = %s\n\n", dest);

// 	ft_memcpy(dest, src, 4);

// 	printf("After memcpy:\n");
// 	printf("src  = %s\n", src);
// 	printf("dest = %s\n", dest);

// 	return (0);
// }