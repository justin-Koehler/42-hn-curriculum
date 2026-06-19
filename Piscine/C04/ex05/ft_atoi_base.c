/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:38:23 by jukohler          #+#    #+#             */
/*   Updated: 2026/02/11 19:09:19 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (!base || ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || is_space(base[i]))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	get_digit_value(char c, char *base)
{
	int	idx;

	idx = 0;
	while (base[idx])
	{
		if (base[idx] == c)
			return (idx);
		idx++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	value;
	int	digit;
	int	base_len;

	if (!is_valid_base(base))
		return (0);
	sign = 1;
	value = 0;
	base_len = ft_strlen(base);
	while (*str && (is_space(*str) || *str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	digit = get_digit_value(*str, base);
	while (digit != -1)
	{
		value = value * base_len + digit;
		str++;
		digit = get_digit_value(*str, base);
	}
	return (value * sign);
}
