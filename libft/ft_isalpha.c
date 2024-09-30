/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:55:17 by smishos           #+#    #+#             */
/*   Updated: 2024/08/21 18:55:08 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	// true or false - is it an alphabetical character?
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
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
// 		printf("%d - %d - %d\n", isalpha(x), ft_isalpha(x), x);
// 		x++;
// 	}
// }