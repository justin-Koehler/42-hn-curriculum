/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdehn <rdehn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:12:39 by rdehn             #+#    #+#             */
/*   Updated: 2026/01/23 19:22:43 by rdehn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	remainder;

	div = *a / *b;
	remainder = *a % *b;
	*a = div;
	*b = remainder;
}
/*
int	main(void)
{
	int	a;
	int	b;

	a = 100;
	b = 3;
	ft_ultimate_div_mod(&a, &b);
	printf("%d", a);
	printf("%d", b);
	return (0);
}
*/