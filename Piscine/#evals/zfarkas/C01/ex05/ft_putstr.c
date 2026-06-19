/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarkas <zfarkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:25:36 by zfarkas           #+#    #+#             */
/*   Updated: 2026/02/01 18:07:42 by zfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);

/*int	main(void)
{
	char	*word;

	word = "abcde";
	ft_putstr(word);
	return (0);
}*/

void	ft_putstr(char *str)
{
	while (*str)
	{
		write (1, str++, 1);
	}
}
