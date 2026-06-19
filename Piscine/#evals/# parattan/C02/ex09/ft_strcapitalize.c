/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:57:31 by parattan          #+#    #+#             */
/*   Updated: 2026/02/04 10:57:35 by parattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	if (*str >= 'a' && *str <= 'z')
		*str = *str - 32;
	return (str);
}

char	*ft_strlowcase(char *str)
{
	if (*str >= 'A' && *str <= 'Z')
		*str = *str + 32;
	return (str);
}

char	*ft_str_first_letter(char *str)
{
	if ((*(str - 1) >= 'a' && *(str - 1) <= 'z'))
		return (str);
	else if ((*(str - 1) >= 'A' && *(str - 1) <= 'Z'))
		return (str);
	else if ((*(str - 1) >= '0' && *(str - 1) <= '9'))
		return (str);
	else
		ft_strupcase(str);
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_strupcase(&str[0]);
	while (str[i])
	{
		if (i > 0)
		{
			ft_strlowcase(&str[i]);
			ft_str_first_letter(&str[i]);
		}
		i++;
	}
	str[i] = '\0';
	return (str);
}
