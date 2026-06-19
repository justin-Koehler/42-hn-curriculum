#include "rush01.h"

//Das Programm nimmt deinen eingegeben Text mit den 16 Regeln, pruft erst, ob genau ein Argument da ist.
//Wenn das passt versucht es das Ratsel zu losen und gibt entweder das geloste Gitter oder "Error" aus.

int	main(int argc, char **argv)  //argc: argument count, argv: argument vector
{
	int	rules[16]; // speicherplatz fur 16 ganze zahlen fuer die eingabebedingungen
	int	board[BOARD_SIZE][BOARD_SIZE] = {{0}}; //initialisiert ein 4x4 gitter mit nullen

	if (argc != 2 || !read_rules(argv[1], rules)) //wenn nicht genau ein argument ubergeben wurde oder wenn der input nicht korrekt geparst werden konnte
		return (output_str("Error\n"), 1); //gibt "Error" aus und beendet das programm mit fehlercode 1
	if (!solve_board(board, rules, 0)) // ruft die funktion solve_board auf, um das gitter zu losen. mit den parametern: board, eingabebedingungen und startposition 0
		output_str("Error\n"); //wenn das gitter nicht gelost werden konnte, gibt "Error" aus
	else //wenn das gitter erfolgreich gelost wurde
		print_board(board); //gibt das geloste gitter aus
	return (0); //beendet das programm erfolgreich
}

