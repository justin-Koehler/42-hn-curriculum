/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfakur <sfakur@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:45:06 by sfakur            #+#    #+#             */
/*   Updated: 2026/01/31 11:24:51 by sfakur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	str1;
	int	str2;
	int	count;
	int	size;

	str1 = 0;
	str2 = 0;
	count = 0;
	while (s1[str1] != '\0')
		str1++;
	while (s2[str2] != '\0')
		str2++;
	if (str2 >= str1)
		size = str2;
	else
		size = str1;
	while (count < size)
	{
		if (s1[count] > s2[count])
			return (s1[count] - s2[count]);
		if (s1[count] < s2[count])
			return (s1[count] - s2[count]);
		count++;
	}
	return (0);
}
// int main() {
//     printf("%d\n",ft_strcmp("HELLa", "HELLi"));
// }
