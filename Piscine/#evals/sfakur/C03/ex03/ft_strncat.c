/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfakur <sfakur@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 12:09:50 by sfakur            #+#    #+#             */
/*   Updated: 2026/01/31 12:12:12 by sfakur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	str1;
	unsigned int	str2;
	unsigned int	counter;

	str1 = 0;
	str2 = 0;
	counter = 0;
	while (dest[str1] != '\0')
		str1++;
	while (src[str2] != '\0')
		str2++;
	while (counter < nb)
	{
		dest[str1] = src[counter];
		dest[str1 + 1] = '\0';
		str1++;
		counter++;
	}
	return (dest);
}
