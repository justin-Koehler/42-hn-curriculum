/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:37:22 by jukohler          #+#    #+#             */
/*   Updated: 2026/02/11 19:08:21 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

static int	base_len(char *base)
{
	int	len;

	len = 0;
	while (base[len])
		len++;
	return (len);
}

static int	is_valid_base(char *base)
{
	int	len;
	int	i;
	int	j;

	if (!base)
		return (0);
	len = base_len(base);
	if (len < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || is_space(base[i]))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	putnbr_base_rec(long nb, char *base, int len)
{
	char	c;

	if (nb >= len)
		putnbr_base_rec(nb / len, base, len);
	c = base[nb % len];
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	long	nb;

	if (!is_valid_base(base))
		return ;
	len = base_len(base);
	nb = nbr;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	putnbr_base_rec(nb, base, len);
}
