/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:45:00 by jukohler          #+#    #+#             */
/*   Updated: 2026/02/11 17:35:35 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

int	count_digits(long nbr, int base_len)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		count = 1;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		nbr /= base_len;
		count++;
	}
	return (count);
}

char	*ft_itoa_base(int nbr, char *base)
{
	char	*result;
	int		base_len;
	int		len;
	long	nb;

	base_len = ft_strlen(base);
	nb = nbr;
	len = count_digits(nb, base_len);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (nb < 0)
	{
		result[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		result[0] = base[0];
	while (nb > 0)
	{
		result[--len] = base[nb % base_len];
		nb /= base_len;
	}
	return (result);
}
