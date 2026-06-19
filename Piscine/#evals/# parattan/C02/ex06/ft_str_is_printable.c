/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:56:53 by parattan          #+#    #+#             */
/*   Updated: 2026/02/04 10:56:56 by parattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	is_printable;

	is_printable = 1;
	while (*str != '\0')
	{
		if (!(*str >= 32 && *str <= 126))
		{
			is_printable = 0;
		}
		str++;
	}
	return (is_printable);
}
