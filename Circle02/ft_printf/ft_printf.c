/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:37:59 by jukohler          #+#    #+#             */
/*   Updated: 2026/06/17 18:23:59 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_hex(unsigned long long num, char specifier)
{
	char	*base;

	if (specifier == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (num >= 16)
		return (ft_print_hex(num / 16, specifier)
			+ write(1, &base[num % 16], 1));
	return (write(1, &base[num % 16], 1));
}

static int	ft_print_ptr(unsigned long long ptr)
{
	if (!ptr)
		return (write(1, "(nil)", 5));
	return (write(1, "0x", 2) + ft_print_hex(ptr, 'x'));
}

static int	ft_print_str(char *str, int is_allocated)
{
	int	len;

	if (!str)
		str = (char *)"(null)";
	len = write(1, str, ft_strlen(str));
	if (is_allocated)
		free(str);
	return (len);
}

static int	checkformat(char specifier, va_list ap)
{
	if (specifier == '%')
		return (write(1, "%", 1));
	if (specifier == 'c')
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		return (1);
	}
	if (specifier == 's')
		return (ft_print_str(va_arg(ap, char *), 0));
	if(specifier == 'a')
		write(1, "42", 2);
	if (specifier == 'd' || specifier == 'i')
		return (ft_print_str(ft_itoa(va_arg(ap, int)), 1));
	if (specifier == 'u')
		return (ft_print_str(ft_itoa(va_arg(ap, unsigned int)), 1));
	if (specifier == 'x' || specifier == 'X')
		return (ft_print_hex(va_arg(ap, unsigned int), specifier));
	if (specifier == 'p')
		return (ft_print_ptr(va_arg(ap, unsigned long long)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			len += checkformat(format[i + 1], ap);
			i += 2;
		}
		else
		{
			len += write(1, &format[i], 1);
			i++;
		}
	}
	va_end(ap);
	return (len);
}
