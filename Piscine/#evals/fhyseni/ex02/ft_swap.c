/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyseni <fhyseni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:55:47 by fhyseni           #+#    #+#             */
/*   Updated: 2026/01/27 19:39:12 by fhyseni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

void	ft_swap(int	*a,	int *b)
{
	int	p1;

	p1 = *a;
	*a = *b;
	*b = p1;
}

/*	main(void)
{
	int	a;
	int	b;

	a = 10;
	b = 20;
	printf("%d\n", a);
	ft_swap(&a, &b);
	printf("%d\n", a);
	return (0);
*/
