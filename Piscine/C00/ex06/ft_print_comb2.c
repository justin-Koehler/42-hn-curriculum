/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:25:34 by jukohler          #+#    #+#             */
/*   Updated: 2026/02/11 17:35:35 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_comb2(int a, int b)
{
	char	c;

	c = a / 10 + '0';
	write(1, &c, 1);
	c = a % 10 + '0';
	write(1, &c, 1);
	write(1, " ", 1);
	c = b / 10 + '0';
	write(1, &c, 1);
	c = b % 10 + '0';
	write(1, &c, 1);
	if (a != 98 || b != 99)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			print_comb2(a, b);
			b++;
		}
		a++;
	}
}
