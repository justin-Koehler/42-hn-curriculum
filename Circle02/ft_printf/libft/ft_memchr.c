/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaurer <zmaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 18:38:42 by zmaurer           #+#    #+#             */
/*   Updated: 2026/05/23 18:41:30 by zmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*ptr;

	ptr = (const unsigned char *)str;
	while (n-- > 0)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str[] = "Hello there";

// 	void *my_result = ft_memchr(str, 't', strlen(str));
// 	void *real_result = memchr(str, 't', strlen(str));

// 	printf("Original string: %s\n\n", str);

// 	printf("ft_memchr result:   %s\n", (char *)my_result);
// 	printf("real memchr result: %s\n\n", (char *)real_result);

// 	my_result = ft_memchr(str, 'x', strlen(str));
// 	real_result = memchr(str, 'x', strlen(str));

// 	printf("Searching for 'x'\n");
// 	printf("ft_memchr:   %p\n", my_result);
// 	printf("real memchr: %p\n", real_result);

// 	return (0);
// }