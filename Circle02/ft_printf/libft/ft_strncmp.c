/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaurer <zmaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 19:17:53 by zmaurer           #+#    #+#             */
/*   Updated: 2026/05/24 12:32:38 by zmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && i < n - 1 && str1[i] && str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

// int	main(void)
// {
// 	const char *s1 = "hello";
// 	const char *s2 = "hello";
// 	const char *s3 = "hella";
// 	printf("s1 vs s2 (n=5): %d\n", ft_strncmp(s1, s2, 5));
// 	printf("s1 vs s3 (n=5): %d\n", ft_strncmp(s1, s3, 5));
// 	return (0);
// }