/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 12:17:25 by alevadni          #+#    #+#             */
/*   Updated: 2026/01/28 13:54:08 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	write_x(int x);
void	write_y(int x);

void	rush(int x, int y)
{
	int	i;

	if (x < 0 || y < 0)
	{
		return ;
	}
	if (y > 1)
	{
		write_x(x);
		if (y > 2)
		{
			i = 1;
			while (i <= y - 2)
			{
				write_y(x);
				i++;
			}
		}
		write_x(x);
	}
	else
	{
		write_x(x);
	}
}

void	write_x(int x)
{
	int	i;

	i = 1;
	while (i <= x)
	{
		if (i == 1 || i == x)
	}
		{
			ft_putchar('o');
		}
		else
		{
			ft_putchar('-');
		}
		i++;

	}
	ft_putchar('\n');
}

void	write_y(int x)
{
	int	i;

	i = 1;      
	while (i <= x)
	{
		if (i == 1 || i == x)
		{
			ft_putchar('|');
		}
		else
		{
			ft_putchar(' ');
		}
		i++;
	}
	ft_putchar('\n');
}
