/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhyseni <fhyseni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 19:44:18 by fhyseni           #+#    #+#             */
/*   Updated: 2026/01/31 23:23:28 by fhyseni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

// int main(void)
// {
// 	int a;
// 	int b;

// 	int div;
// 	int mod;

// 	a = 12;
// 	b = 5 ;

// 	ft_div_mod(a, b, &div, &mod);
// 	printf("%d\n", div);
// 	printf("%d\n", mod);
// 	return (0);
// }
