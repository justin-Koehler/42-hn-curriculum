/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaurer <zmaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 18:58:24 by zmaurer           #+#    #+#             */
/*   Updated: 2026/05/23 18:58:48 by zmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int	main(void)
// {
// 	ft_putchar_fd('H', 1);
// 	ft_putchar_fd('e', 1);
// 	ft_putchar_fd('l', 1);
// 	ft_putchar_fd('l', 1);
// 	ft_putchar_fd('o', 1);
// 	ft_putchar_fd('\n', 1);

// 	return (0);
// }