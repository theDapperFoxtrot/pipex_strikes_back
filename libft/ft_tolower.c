/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:00:21 by smishos           #+#    #+#             */
/*   Updated: 2024/04/27 15:54:34 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// convert the upper case letter to a lowercase one
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	else
		return (c);
}

// #include <stdio.h>
// #include <ctype.h>
// // 65 - 90
// int main()
// {
// 	int x = 65;

// 	while (x < 91)
// 	{
// 		printf("%c - %c\n", tolower(x), ft_tolower(x));
// 		x++;
// 	}
// 	return (0);
// }