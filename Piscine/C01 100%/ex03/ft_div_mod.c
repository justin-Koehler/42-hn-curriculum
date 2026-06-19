/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 01:38:48 by jukohler          #+#    #+#             */
/*   Updated: 2026/01/26 17:07:57 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
	
	write(1, "Division: ", 10);
	write(1, &(*div), 4);
	write(1, "\nModulus: ", 10);
	write(1, &(*mod), 4); 
	write(1, "\n", 1);
}

int main(void)
{
	int a;
	int b;
	int div;
	int mod;

	a = 10;
	b = 3;
	ft_div_mod(a, b, &div, &mod);
	
	return (0);
}
