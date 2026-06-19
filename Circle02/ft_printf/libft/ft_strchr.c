/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaurer <zmaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 19:13:03 by zmaurer           #+#    #+#             */
/*   Updated: 2026/05/23 19:14:44 by zmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	find;

	i = 0;
	find = (unsigned char)c;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == find)
			return ((char *)s + i);
		i++;
	}
	if (find == '\0')
		return ((char *)s + i);
	return (NULL);
}

// int	main(void)
// {
// 	const char	str[] = "Hello world";

// 	char	*p1;
// 	char	*p2;
// 	char	*p3;

// 	p1 = ft_strchr(str, 'o');
// 	p2 = ft_strchr(str, 'w');
// 	p3 = ft_strchr(str, 'z');

// 	printf("Searching in: %s\n", str);

// 	if (p1)
// 		printf("First 'o': %s\n", p1);
// 	else
// 		printf("No 'o' found\n");

// 	if (p2)
// 		printf("First 'w': %s\n", p2);
// 	else
// 		printf("No 'w' found\n");

// 	if (p3)
// 		printf("First 'z': %s\n", p3);
// 	else
// 		printf("No 'z' found\n");

// 	return (0);
// }