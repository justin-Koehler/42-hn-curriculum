#include "rush01.h"

//Geht Feld fur feld durchs Gitterprobiert in jedes Feld nacheinander die Zahlen 1 bis 4 einzufugen und uberpruft dabei, ob die Eingabebedingungen erfullt werden.
//Wenn eine Zahl passt, wird die Funktion rekursiv fur das nachste Feld aufgerufen.
//Wenn alle Felder gefullt sind, wird uberpruft, ob das Gitter die Eingabebedingungen erfullt.
//Wenn eine Zahl nicht passt, wird zuruckgegangen und die naechste Zahl versucht.

int	solve_board(int board[BOARD_SIZE][BOARD_SIZE], int *rules, int cell_index) //pos: aktuelle position im gitter (0 bis 15) 
{
	int	candidate_height;
	int	row;
	int	col;

	if (cell_index == 16) //wenn alle positionen im gitter gefullt sind 
		return (check_rules(board, rules)); //uberpruft, ob das gitter die eingabebedingungen erfullt
	row = cell_index / 4;
	col = cell_index % 4;
	candidate_height = 0;
	while (++candidate_height <= 4) //solange candidate_height von 1 bis 4 
		if (is_safe(board, row, col, candidate_height) //uberpruft, ob die zahl in der aktuellen position platziert werden kann indem sie die regeln des spiels beachtet die regeln sind: keine doppelten zahlen in reihen und spalten
			&& (board[row][col] = candidate_height) //platziert die zahl im gitter
			&& solve_board(board, rules, cell_index + 1)) //rekursiver aufruf der funktion fur die nachste position im gitter
			return (1); //wenn eine losung gefunden wurde, gibt 1 zuruck
		else if (board[row][col]) //wenn die zahl nicht passt
			board[row][col] = 0; //setzt die aktuelle position im gitter zuruck, wenn die zahl nicht passt
	return (0); //wenn keine losung gefunden wurde, gibt 0 zuruck
}
