/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdehn <rdehn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:39:19 by rdehn             #+#    #+#             */
/*   Updated: 2026/01/23 19:18:23 by rdehn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *a, int *b);

void	ft_swap(int *a, int *b)
{
	int	v;

	v = *a;
	*a = *b;
	*b = v;
}
/*
int	main(void)
{
	int	a_to_int;
	int	b_to_int;

	a_to_int = 777;
	b_to_int = 88;

	printf("%d", a_to_int);
	printf(" ");
	printf("%d", b_to_int);
	printf("/");
	ft_swap(&a_to_int, &b_to_int);
	printf("%d", a_to_int);
	printf(" ");
	printf("%d", b_to_int);
	return (0);
}
*/