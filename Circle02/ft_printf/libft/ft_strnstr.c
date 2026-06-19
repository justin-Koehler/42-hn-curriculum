/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaurer <zmaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 19:17:51 by zmaurer           #+#    #+#             */
/*   Updated: 2026/05/24 12:33:33 by zmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j]
			&& little[j]
			&& big[i + j] == little[j]
			&& i + j < len)
		{
			j++;
		}
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char *big = "Hello world 42";
// 	const char *little1 = "world";
// 	const char *little2 = "42";
// 	const char *little3 = "Hello";

// 	char *res;

// 	printf("big: '%s'\n\n", big);

// 	res = ft_strnstr(big, little1, 15);
// 	printf("search 'world' (len=15): %s\n", res);

// 	res = ft_strnstr(big, little2, 15);
// 	printf("search '42' (len=15): %s\n", res);

// 	res = ft_strnstr(big, little3, 5);
// 	printf("search 'Hello' (len=5): %s\n", res);

// 	return (0);
// }