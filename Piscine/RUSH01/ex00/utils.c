#include "rush01.h"
#include <unistd.h>

// Gibt ein einzelnes Zeichen auf die Standardausgabe aus.

void	output_char(char ch)
{
	write(1, &ch, 1);
}

void	output_str(char *str) 
{
	while (*str) //solange das aktuelle zeichen nicht der null-terminator ist
		output_char(*str++);
}

void	print_board(int board[4][4]) //gibt das 4x4 gitter aus 
{
	int	row;
	int	col;

	row = -1;
	while (++row < 4)
	{
		col = -1;
		while (++col < 4)
		{
			output_char(board[row][col] + '0'); //konvertiert die zahl in ein zeichen und gibt sie aus indem '0' addiert wird
			output_char(col < 3 ? ' ' : '\n');
		}
	}
}
