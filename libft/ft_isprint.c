/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:52:57 by smishos           #+#    #+#             */
/*   Updated: 2024/08/21 18:55:19 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>

int	ft_isprint(int c)
{
	// true or false - is it a printable character?
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

// #include <stdio.h>

// int main()
// {
// 	int x =  -20;
// 	while( x < 300)
// 	{
// 		printf("%d - %d - %d\n", isprint(x), ft_isprint(x), x);
// 		x++;
// 	}
// return (0);
// }
