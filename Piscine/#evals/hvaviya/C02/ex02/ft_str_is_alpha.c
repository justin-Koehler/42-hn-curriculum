/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvaviya <hvaviya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:49:04 by hvaviya           #+#    #+#             */
/*   Updated: 2026/02/01 18:03:25 by hvaviya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	is_alphabetic(char c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

int	ft_str_is_alpha(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
	{
		if (!is_alphabetic(str[counter]))
		{
			return (0);
		}
		counter++;
	}
	return (1);
}

// int	main(void)
// {
// 	int	c;

// 	c = ft_str_is_alpha("bcghij[`aBCZ");
// 	printf("%d", c);
// 	return (0);
// }
