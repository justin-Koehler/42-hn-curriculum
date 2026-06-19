/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolf <ewolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:27:36 by ewolf             #+#    #+#             */
/*   Updated: 2026/02/04 13:12:19 by ewolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
	{
		i++;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int		minus;
	int		result;
	int		i;

	i = ft_isspace(str);
	minus = 1;
	result = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
		if (result == -2147483648)
			return (-2147483648);
		if (str[i] < '0' || str[i] > '9')
			return (result * minus);
	}
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%d", ft_atoi(" \n \t \v -+-2147483647Y999"));
// }