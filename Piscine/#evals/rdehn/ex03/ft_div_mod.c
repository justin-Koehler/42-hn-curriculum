/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdehn <rdehn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:09:11 by rdehn             #+#    #+#             */
/*   Updated: 2026/01/23 19:20:25 by rdehn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main(void)
{
	int	x_div;
	int	x_mod;
	
	ft_div_mod(100, 3, &x_div, &x_mod);
	printf("%d", x_div);
	printf(" ");
	printf("%d", x_mod);
	return (0);
}
*/