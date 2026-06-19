/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaurer <zmaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 18:42:00 by zmaurer           #+#    #+#             */
/*   Updated: 2026/05/23 18:50:05 by zmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t				i;
	const unsigned char	*a;
	const unsigned char	*b;

	i = 0;
	a = str1;
	b = str2;
	while (i < n)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}

// int main(void)
// {
//     char a1[] = "abcdef";
//     char a2[] = "abcxef";
//     char b1[] = {10, 20, 30, 40};
//     char b2[] = {10, 20, 99, 40};
//     char c1[] = "hello";
//     char c2[] = "hello";
//     size_t n;
//     printf("=== STRING TEST ===\n");
//     n = strlen(a1);
//     printf("ft_memcmp : %d\n", ft_memcmp(a1, a2, n));
//     printf("memcmp    : %d\n\n", memcmp(a1, a2, n));
//     printf("=== BYTE ARRAY TEST ===\n");
//     n = sizeof(b1);
//     printf("ft_memcmp : %d\n", ft_memcmp(b1, b2, n));
//     printf("memcmp    : %d\n\n", memcmp(b1, b2, n));
//     printf("=== EQUAL TEST ===\n");
//     n = strlen(c1);
//     printf("ft_memcmp : %d\n", ft_memcmp(c1, c2, n));
//     printf("memcmp    : %d\n", memcmp(c1, c2, n));
//     return 0;
// }
