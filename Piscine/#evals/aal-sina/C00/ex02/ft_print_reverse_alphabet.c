/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-sina <aal-sina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:47:23 by aal-sina          #+#    #+#             */
/*   Updated: 2026/01/29 13:06:26 by aal-sina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	c;

	c = 122;
	while (c > 96)
	{
		write(1, &c, 1);
		c--;
	}
}

// int	main(void)
// {
// 	ft_print_reverse_alphabet();
// 	return 0;
// }