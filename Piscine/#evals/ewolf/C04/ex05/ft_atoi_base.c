/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolf <ewolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:42:12 by ewolf             #+#    #+#             */
/*   Updated: 2026/02/04 13:07:11 by ewolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_base(char cur, char *base)
{
	int		i;

	i = 0;
	while (base[i])
	{
		if (base[i] == cur)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_power(int base, int power)
{
	int	out;

	out = 1;
	while (power-- > 0)
		out *= base;
	return (out);
}

int	ft_base_dec(char *str, char *base)
{
	int		i;
	int		pos;
	int		out;
	int		len_str;
	int		len_base;

	i = 0;
	pos = 0;
	out = 0;
	len_str = 0;
	len_base = 0;
	while (base[len_base])
		len_base++;
	while (str[len_str])
		len_str++;
	while (str[pos])
	{
		while (str[pos] != base[i])
			i++;
		out += i * ft_power(len_base, len_str - pos++ - 1);
		i = 0;
	}
	return (out);
}

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

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		pos;
	int		minus;
	int		out;
	char	correct[200];

	out = 0;
	i = ft_isspace(str);
	pos = 0;
	minus = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (ft_is_base(str[i], base) == 1)
		correct[pos++] = str[i++];
	correct[pos] = '\0';
	return (ft_base_dec(correct, base) * minus);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("\n%d", ft_atoi_base(" --+1111111111111111111111111111111", "01"));
// // 	char str[200];
// // 	ft_find_base_string("  -- -+--+123ABab567", "0123456789ABCDEF", str);
// // 	printf("res: %s\n", str);
// }