#ifndef RUSH01_H //guard against multiple inclusions
# define RUSH01_H
# define BOARD_SIZE 4 //definiert die grose des gitters als 4x4

void	output_char(char ch);
void	output_str(char *str);
int		read_rules(char *text, int *rules);
int		solve_board(int board[BOARD_SIZE][BOARD_SIZE], int *rules, int cell);
int		is_safe(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int height);
int		check_rules(int board[BOARD_SIZE][BOARD_SIZE], int *rules);
void	print_board(int board[BOARD_SIZE][BOARD_SIZE]);

#endif
