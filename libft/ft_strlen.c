/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:06:26 by smishos           #+#    #+#             */
/*   Updated: 2024/05/02 15:30:09 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// return an unsigned long (size_t) that states the length of the string
size_t	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char *jedi =  "Hello there";
// 	char *jedi2 =  "General Kenobi";

// 	printf("%zu - %zu\n", strlen(jedi), ft_strlen(jedi));
// 	printf("%zu - %zu\n", strlen(jedi2), ft_strlen(jedi2));
// 	return (0);
// }