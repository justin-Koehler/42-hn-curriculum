/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:56:33 by parattan          #+#    #+#             */
/*   Updated: 2026/02/04 10:56:38 by parattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	is_lowercase;

	is_lowercase = 1;
	while (*str != '\0')
	{
		if (!((*str >= 'a' && *str <= 'z')))
		{
			is_lowercase = 0;
		}
		str++;
	}
	return (is_lowercase);
}
