/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarkas <zfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 11:41:40 by zfarkas           #+#    #+#             */
/*   Updated: 2026/02/01 17:23:44 by zfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b);

/*int	main(void)
{
	int	num1;
	int	num2;	
	int	*a;
	int	*b;

	num1 = 5;
	num2 = 10;
	a = &num1;
	b = &num2;
	ft_ultimate_div_mod(a, b);
}*/

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	firstnum;
	int	secondnum;

	firstnum = *a;
	secondnum = *b;
	*a = firstnum / secondnum;
	*b = firstnum % secondnum;
}
