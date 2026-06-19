/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test405.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:10:50 by mroux             #+#    #+#             */
/*   Updated: 2019/08/05 16:17:05 by mroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int		ft_atoi_base(char *str, char *base);
//int 	map_to_value(char c, char *base, int nbase);
int		main(void)
{
	char *s = "--+-- -+0015 20";
	char *s1 = " 	+	-  FE";
	printf("%d\n", ft_atoi_base(s,"0123456789"));
	printf("%d\n", ft_atoi_base(s1,"01234567089ABCDEF"));
	printf("%d\n", ft_atoi_base("---+-120t00","0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("FFFFFFFF","01234567089ABCDEF"));
	return 0;
}
