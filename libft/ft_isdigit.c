/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:51:43 by smishos           #+#    #+#             */
/*   Updated: 2024/08/21 18:55:15 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	// true or false - is it a digit (0-9)
	if (c >= 48 && c <= 57)
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
// 		printf("%d - %d - %d\n", isdigit(x), ft_isdigit(x), x);
// 		x++;
// 	}
// }