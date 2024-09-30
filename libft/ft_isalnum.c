/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:55:11 by smishos           #+#    #+#             */
/*   Updated: 2024/08/21 18:55:05 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	//true or false - is it alphanumeric?
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
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
// 		printf("%d - %d - %d\n", isalnum(x), ft_isalnum(x), x);
// 		x++;
// 	}
// }