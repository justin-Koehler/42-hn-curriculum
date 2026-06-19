/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amillaku <amillaku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:20:35 by amillaku          #+#    #+#             */
/*   Updated: 2026/01/29 18:33:38 by amillaku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_alnum(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'
			&& c <= '9'));
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	nw;

	i = 0;
	nw = 1;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z' && nw)
			str[i] -= 32;
		else if (str[i] >= 'A' && str[i] <= 'Z' && !nw)
			str[i] += 32;
		nw = !is_alnum(str[i]);
		i++;
	}
	return (str);
}
