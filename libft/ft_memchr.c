/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:28:03 by smishos           #+#    #+#             */
/*   Updated: 2024/08/09 13:42:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//locate a byte in the string
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr; //allows you to traverse the string (you can't alter constants)
	unsigned char	character; //there are no negative ascii values, so converting to unsigned is intuitive

	ptr = (unsigned char *) s;
	character = (unsigned char) c;
	while (n-- > 0) //leverage n as a counter
	{
		if (*ptr == character) //if the charcter at the current pointer position is what we're looking for
			return (ptr); //return the pointer
		ptr++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char	jedi[] = "Hello there";
// 	printf("%s\n", ft_memchr(jedi, 'o', 1));
// 	printf("%s\n", memchr(jedi, 'o', 1));
// 	return (0);
// }