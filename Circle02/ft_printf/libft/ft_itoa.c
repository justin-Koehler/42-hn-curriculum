/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 18:31:56 by zmaurer           #+#    #+#             */
/*   Updated: 2026/05/24 15:06:09 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
#include "libft.h"

static int	count_digits(long n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		len;

	num = n;
	len = count_digits(num);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num < 0)
	{ 
		str[0] = '-';
		num = -num;
	}
	while (len > (n < 0))
	{
		len--;
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

// int main(void)
// {
//     int tests[] = {
//         0,
//         5,
//         42,
//         -42,
//         1234,
//         -1234,
//         2147483647,
//         -2147483648
//     };

//     int i = 0;
//     int len = sizeof(tests) / sizeof(tests[0]);

//     while (i < len)
//     {
//         char *result;

//         result = ft_itoa(tests[i]);

//         if (result == NULL)
//         {
//             printf("malloc failed\n");
//             return (1);
//         }

//         printf("input: %d -> output: %s\n", tests[i], result);

//         free(result);

//         i++;
//     }

//     return (0);
// }
