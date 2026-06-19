/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parattan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:58:39 by parattan          #+#    #+#             */
/*   Updated: 2026/02/04 10:58:40 by parattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_addr(void *addr)
{
	int					c;
	char				digit;
	char				addr_ptr[16];
	char				*table;
	unsigned long long	value;

	c = 0;
	table = "0123456789abcdef";
	value = (unsigned long long)addr;
	while (value)
	{
		digit = table[value % 16];
		value = value / 16;
		addr_ptr[15 - c] = digit;
		c++;
	}
	while (c < 16)
	{
		addr_ptr[15 - c] = '0';
		c++;
	}
	write(1, addr_ptr, 16);
}

void	print_hexadecimal(char *str)
{
	int		quotient;
	int		remainder;
	char	*tab;

	tab = "0123456789abcdef";
	quotient = *str / 16;
	remainder = *str % 16;
	write(1, &tab[quotient], 1);
	write(1, &tab[remainder], 1);
}

void	ft_putstr_hexadecimal(char *str)
{
	int	size;

	size = 0;
	while (size < 16 && *str)
	{
		print_hexadecimal(str);
		str++;
		print_hexadecimal(str);
		str++;
		write(1, " ", 1);
		size = size + 2;
	}
	while (size < 16)
	{
		write(1, "    ", 4);
		write(1, " ", 1);
		size = size + 2;
	}
}

void	print_string(char *str)
{
	int	size;

	size = 0;
	while (size < 16 && *str)
	{
		if (*str >= 0 && *str < 32)
			write(1, ".", 1);
		else
			write(1, str, 1);
		size++;
		str++;
	}
	if (size < 16)
		write(1, ".", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		c;

	c = 0;
	while (c < size)
	{
		if (c % 16 == 0)
		{
			ft_print_addr(addr);
			write(1, ": ", 2);
			ft_putstr_hexadecimal(addr);
			print_string(addr);
			write(1, "\n", 1);
		}
		c++;
		addr++;
	}
	return (addr);
}
