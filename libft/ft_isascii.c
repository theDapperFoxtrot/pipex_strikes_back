/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:58:35 by smishos           #+#    #+#             */
/*   Updated: 2024/08/21 18:55:12 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	// true or false - is it on the standard ascii table?
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

// #include <ctype.h>
// #include <stdio.h>

// int main()
// {
// 	int x =  -20;
// 	while( x < 530)
// 	{
// 		printf("%d - %d - %d\n", isascii(x), ft_isascii(x), x);
// 		x++;
// 	}
// }