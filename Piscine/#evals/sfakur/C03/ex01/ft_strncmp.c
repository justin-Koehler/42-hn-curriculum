/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfakur <sfakur@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:25:30 by sfakur            #+#    #+#             */
/*   Updated: 2026/01/31 11:28:49 by sfakur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	str1;
	unsigned int	str2;
	unsigned int	count;

	str1 = 0;
	str2 = 0;
	while (s1[str1] != '\0')
		str1++;
	while (s2[str2] != '\0')
		str2++;
	count = 0;
	if (n > 0)
	{
		while (count < n)
		{
			if (s1[count] > s2[count])
				return (s1[count] - s2[count]);
			if (s1[count] < s2[count])
				return (s1[count] - s2[count]);
			count++;
		}
	}
	return (0);
}
