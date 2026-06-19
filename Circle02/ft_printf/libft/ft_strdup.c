/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaurer <zmaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 19:15:51 by zmaurer           #+#    #+#             */
/*   Updated: 2026/05/24 12:31:15 by zmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strdup(const char *str1)
{
	char	*dup;
	char	*start;

	dup = malloc(ft_strlen(str1) + 1);
	if (dup == NULL)
		return (NULL);
	start = dup;
	while (*str1)
	{
		*dup = *str1;
		dup++;
		str1++;
	}
	*dup = '\0';
	return (start);
}

// int	main(void)
// {
// 	const char	str1[] = "Hello world";
// 	char		*copy;

// 	copy = ft_strdup(str1);

// 	if (!copy)
// 	{
// 		printf("malloc failed\n");
// 		return (1);
// 	}

// 	printf("original: %s\n", str1);
// 	printf("copy    : %s\n", copy);

// 	copy[0] = 'h';

// 	printf("\nAfter modifying copy:\n");
// 	printf("original: %s\n", str1);
// 	printf("copy    : %s\n", copy);

// 	free(copy);

// 	return (0);
// }