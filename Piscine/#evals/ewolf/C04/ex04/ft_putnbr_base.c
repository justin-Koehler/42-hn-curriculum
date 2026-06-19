/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolf <ewolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:33:48 by ewolf             #+#    #+#             */
/*   Updated: 2026/02/03 19:12:25 by ewolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_base(long number, int len, char *base)
{
	char	arr[200];
	int		i;

	i = 0;
	if (number < 0)
	{
		number *= -1;
		write(1, "-", 1);
	}
	if (number == 0)
		write(1, &base[0], 1);
	while (number != 0)
	{
		arr[i++] = base[number % len];
		number /= len;
	}
	arr[i] = '\0';
	while (i != 0)
		write(1, &arr[--i], 1);
}

int	ft_is_valid(char *base)
{
	int		len;
	int		cur;

	len = 0;
	cur = 0;
	while (base[len])
	{
		while (base[cur])
		{
			if ((base[cur] == base[len] && cur != len) || base[cur] == '+'\
			|| base[cur] == '-' || base[cur] == ' ')
				return (0);
			cur++;
		}
		cur = 0;
		len++;
	}
	if (len > 1)
		return (1);
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		len;
	long	number;

	number = nbr;
	i = 0;
	len = 0;
	while (base[len])
		len++;
	if (ft_is_valid(base) == 1)
	{
		ft_write_base(number, len, base);
	}
}

// int main(void)
// {
// 	ft_putnbr_base(15, "0123456789ABCDEF");
// }