/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:06:18 by smishos           #+#    #+#             */
/*   Updated: 2024/08/21 18:55:22 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(int c)
{
		// true or false - is it a whitespace character?
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

// #include <ctype.h>
// #include <stdio.h>

// int main()
// {
// 	int x =  -20;
// 	while( x < 300)
// 	{
// 		printf("%d - %d - %d\n", isspace(x), ft_isspace(x), x);
// 		x++;
// 	}
// return (0);
// }