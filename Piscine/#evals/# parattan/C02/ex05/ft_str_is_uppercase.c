/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:56:45 by parattan          #+#    #+#             */
/*   Updated: 2026/02/04 10:56:46 by parattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	is_uppercase;

	is_uppercase = 1;
	while (*str != '\0')
	{
		if (!(*str >= 'A' && *str <= 'Z'))
		{
			is_uppercase = 0;
		}
		str++;
	}
	return (is_uppercase);
}
