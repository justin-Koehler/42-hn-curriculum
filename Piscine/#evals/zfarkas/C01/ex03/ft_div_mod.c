/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarkas <zfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 11:18:02 by zfarkas           #+#    #+#             */
/*   Updated: 2026/02/01 17:24:16 by zfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod);

/*int	main(void)
{
	int	a;
	int	b;
	int	devided;
	int	moded;

	a = 5;
	b = 10;
	devided = 0;
	moded = 0;
	ft_div_mod (a, b, &devided, &moded);
}*/

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
