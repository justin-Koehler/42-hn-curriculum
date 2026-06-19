#include "rush01.h"

int	read_rules(char *text, int *rules)
{
	int	char_index;
	int	rules_count;

	char_index = -1;
	rules_count = 0;
	while (text[++char_index])
		if (text[char_index] >= '1' && text[char_index] <= '4'
			&& rules_count < 16)
			rules[rules_count++] = text[char_index] - '0';
		else if (text[char_index] != ' ')
			return (0);
	return (rules_count == 16);
}
