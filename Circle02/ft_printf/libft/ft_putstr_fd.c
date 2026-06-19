/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaurer <zmaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 19:00:49 by zmaurer           #+#    #+#             */
/*   Updated: 2026/05/23 19:01:19 by zmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

// int	main(void)
// {
// 	char	str1[] = "Hello";
// 	char	str2[] = "libft";
// 	char	str3[] = "12345";

// 	ft_putstr_fd(str1, 1);
// 	write(1, "\n", 1);

// 	ft_putstr_fd(str2, 1);
// 	write(1, "\n", 1);

// 	ft_putstr_fd(str3, 1);
// 	write(1, "\n", 1);

// 	return (0);
// }