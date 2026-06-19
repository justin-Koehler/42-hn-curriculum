/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukohler <jukohler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:39:32 by amillaku          #+#    #+#             */
/*   Updated: 2026/01/23 23:33:21 by jukohler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


int	main(void) // Hauptfunktion zum Testen von ft_putchar
{
	ft_putchar('L'); // Gibt den Buchstaben 'A' aus
	ft_putchar('\n'); // Gibt einen Zeilenumbruch aus
	return (0); // Beendet das Programm erfolgreich
}
