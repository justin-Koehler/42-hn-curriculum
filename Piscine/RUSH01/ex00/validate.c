#include "rush01.h"

// Zählt, wie viele Gebäude von einer bestimmten Seite aus sichtbar sind.
// einfacher ablauf ist: es wird die reihe oder spalte in der angegebenen richtung durchlaufen und die anzahl der sichtbaren gebaude gezahlt indem die maximale gebaudehohe verfolgt wird.
int	count_visible_buildings(int board[4][4], int line_index, int view_direction) //dir: richtung von der aus gezahlt wird //0: oben, 1: unten, 2: links, 3: rechts //index: reihe oder spalte
 {
	int	position_index; //laufvariable
	int	visible_count; //anzahl der sichtbaren gebaude
	int	max_height;//maximale gebaudehohe bisher
	int	current_height;//aktuelle gebaudehohe

	position_index = -1; //initialisiert die laufvariable
	visible_count = 0;
	max_height = 0;
	while (++position_index < 4)
	{
		current_height = view_direction == 0 ? board[position_index][line_index]
			: view_direction == 1 ? board[3 - position_index][line_index]
			: view_direction == 2 ? board[line_index][position_index]
			: board[line_index][3 - position_index];
		if (current_height > max_height && ++visible_count) //wenn die aktuelle gebaudehohe groser ist als die bisherige maximale hohe, wird die sichtbare anzahl erhoht
			max_height = current_height;
	}
	return (visible_count);
}

int	check_rules(int board[4][4], int *rules) //uberpruft, ob das gitter die eingabebedingungen erfullt
{
	int	line_index;

	line_index = -1;
	while (++line_index < 4)
		if (count_visible_buildings(board, line_index, 0) != rules[line_index] // uberpruft jede der 4 richtungen fur jede reihe und spalte indem die sichtbaren gebaude gezahlt werden und mit den eingabebedingungen verglichen werden
			|| count_visible_buildings(board, line_index, 1) != rules[4 + line_index]
			|| count_visible_buildings(board, line_index, 2) != rules[8 + line_index]
			|| count_visible_buildings(board, line_index, 3) != rules[12 + line_index])
			return (0);
	return (1);
}

int	is_safe(int board[4][4], int row, int col, int height) //uberpruft, ob die zahl in der aktuellen position platziert werden kann 
{
	int	check_index;

	check_index = -1;
	while (++check_index < 4) //uberpruft die reihe und spalte auf doppelte zahlen
		if (board[row][check_index] == height // wenn die zahl bereits in der reihe vorhanden ist
			|| board[check_index][col] == height) //wenn die zahl bereits in der reihe oder spalte vorhanden ist
			return (0);
	return (1);
}
