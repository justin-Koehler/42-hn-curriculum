/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaurer <zmaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 19:17:56 by zmaurer           #+#    #+#             */
/*   Updated: 2026/05/23 19:33:12 by zmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned
int, char))
{
	char			*newstr;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	newstr = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	random_function(unsigned int i, char c)
{
	(void)i;
	return (c + 1);
}

// int	main(void)
// {
//     char const  *str = "Hey";
//     char        *res;

//     res = ft_strmapi(str, random_function);
//     if (!res)
//         return(1);

//     printf("original: %s\n", str);
//     printf("result: %s\n", res);

//     free(res);
//     return(0);
// }