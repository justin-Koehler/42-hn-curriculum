/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:56:06 by parattan          #+#    #+#             */
/*   Updated: 2026/02/04 15:56:10 by parattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	if (ft_strlen(src) < 1)
		return (ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
/*
int	main(void)
{
	char	dst1[200];
	char	dst2[200];
	char	dst3[200];
	char	dst4[200] = "";
//	char	dst5[200];

	printf("Case 1, size 4: %d, %s \n", ft_strlcpy(dst1, "Test", 4), dst1);
	printf("Case 2, size 4: %d, %s \n", ft_strlcpy(dst2, "Teeth", 4), dst2);
	printf("Case 3, size 4: %d, %s \n", ft_strlcpy(dst3, "For", 4), dst3);
	printf("Case 4, size 4: %d, %s \n", ft_strlcpy(dst4, "For", 4), dst4);
//	printf("Case 5, FT: src""< 4sz:%d \n", ft_strlcpy("", "", 4));
	return (0);
}
*/
