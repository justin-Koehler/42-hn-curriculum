/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaurer <zmaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 19:17:49 by zmaurer           #+#    #+#             */
/*   Updated: 2026/05/24 12:32:31 by zmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char	*str, int c)
{
	size_t			i;
	unsigned char	find;
	char			*last;

	i = 0;
	find = (unsigned char)c;
	last = NULL;
	while (str[i] != '\0')
	{
		if ((unsigned char)str[i] == find)
			last = (char *)str + i;
		i++;
	}
	if (find == '\0')
		return ((char *)str + i);
	return (last);
}

// int	main(void)
// {
// 	const char str[] = "Hello world 42 ooo";
// 	char *res;

// 	printf("String: %s\n\n", str);

// 	res = ft_strrchr(str, 'o');
// 	if (res)
// 		printf("Last 'o' found: %s\n", res);
// 	else
// 		printf("'o' not found\n");

// 	return (0);
// }