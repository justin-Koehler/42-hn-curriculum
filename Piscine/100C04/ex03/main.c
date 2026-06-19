#include <stdio.h>
#include <stdlib.h>

int     ft_atoi(char *str);

int		main(void)
{
	char	*str, *str2;

	str = "      ----+---+++2300fesfss65+2";
	str2 = "2300";
	printf("%d\n", ft_atoi(str));
//	printf("%d\n", atoi(str));
}
