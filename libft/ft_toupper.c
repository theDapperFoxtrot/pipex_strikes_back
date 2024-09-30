/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:36:31 by smishos           #+#    #+#             */
/*   Updated: 2024/04/27 15:54:38 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// convert the lowercase letter to an uppercase one
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	else
		return (c);
}

// #include <stdio.h>
// #include <ctype.h>
// // 97 - 122
// int main()
// {
// 	int x = 97;

// 	while (x < 123)
// 	{
// 		printf("%c - %c\n", toupper(x), ft_toupper(x));
// 		x++;
// 	}
// 	return (0);
// }