/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfakur <sfakur@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 12:09:15 by sfakur            #+#    #+#             */
/*   Updated: 2026/01/31 12:09:20 by sfakur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	str1;
	int	str2;
	int	total_size;
	int	counter;

	str1 = 0;
	str2 = 0;
	total_size = 0;
	counter = 0;
	while (dest[str1] != '\0')
		str1++;
	while (src[str2] != '\0')
		str2++;
	total_size = str1 + str2;
	while (str1 < total_size + 1)
	{
		dest[str1] = src[counter];
		dest[str1 + 1] = '\0';
		str1++;
		counter++;
	}
	return (dest);
}
// int main()
// {
//     puts(ft_strcat("hello", "world"));
// }