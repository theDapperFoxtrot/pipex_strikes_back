/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:02:28 by smishos           #+#    #+#             */
/*   Updated: 2024/04/27 15:24:56 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char	*ptr; //create a pointer variable

	ptr = (unsigned char *)b; //currently the received pointer is void, but we want to type cast to a unsigned char pointer to handle strings
	while (length > 0) //loop until the string is set in memory
	{
		*(ptr) = (unsigned char)c; //at each position, assign the chosen value (c)
		ptr++; //increment positions
		length--; //decrement your length of string counter
	}
	return (b); //return the completed task (some number of default values)
}

// #include <stdio.h>

// int main()
// {
// 	char	default_char = '0'; //a default character
// 	char	*empty = ""; //an empty character array
// 	printf("%s", ft_memset(empty, default_char, 12)); //printing the function call, setting the places in memory to the default char
// 	return (0);
// }
