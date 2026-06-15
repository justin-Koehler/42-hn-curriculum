/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:35:53 by jukohler          #+#    #+#             */
/*   Updated: 2026/05/19 13:35:53 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long n)
{
	int	i;

	i = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	long	nb;

	nb = n;
	len = count_digits(nb);
	if (n < 0)
		len++;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (nb < 0)
		nb = -nb;
	while (len-- > (n < 0 ? 1 : 0))
	{
		result[len] = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}