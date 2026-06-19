/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaurer <zmaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 18:15:41 by zmaurer           #+#    #+#             */
/*   Updated: 2026/05/24 12:30:54 by zmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		else
			sign = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

//int main(void)
//{
// 		const char *tests[] = 
//		{
//      	"123",
//      	"   -42",
//      	"+7",
//      	"4193 with words",
//      	"words 123",
//      	"--5",
//      	"+-5",
//      	"",
//      	"000123",
//      	"  +0012a42",
//      	NULL
// 		};
//
//		int i = 0;
//
//    	while (tests[i])
//    	{
//     		printf("input: \"%s\"\n", tests[i]);
//        	printf("ft_atoi: %d\n", ft_atoi(tests[i]));
//        	printf("atoi:    %d\n\n", atoi(tests[i]));
//        	i++;
//    	}
//}