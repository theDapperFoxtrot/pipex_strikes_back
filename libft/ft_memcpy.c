/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:24:37 by smishos           #+#    #+#             */
/*   Updated: 2024/04/27 15:25:03 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;

	if (!dst && !src) //if both pointers are null, return null
		return (NULL);
	i = 0;
	while (i < n) //copy the characters n places far in memory
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

//it's necessary for the destination to have a buffer of sufficient size
//to recieve the copied strings, or else you receive a bus error
//initiating a null destination results in a seg fault

// #include <stdio.h>
// #include <string.h>

// int	main()
// {
// 	char	*jedi = "";
// 	char	jedi2[15] = "";

// 	char	*jedi3 = "Hello there";
// 	char	jedi4[15] = "";

// 	printf("\nMY FUNCTION\n");
// 	printf("Source:|%s|\n", jedi);
// 	ft_memcpy(jedi2, jedi, 15);
// 	printf("Destination:|%s|\n", jedi2);

// 	printf("\nSTANDARD FUNCTION\n");
// 	printf("Source: %s\n", jedi3);
// 	memcpy(jedi4, jedi3, 15);
// 	printf("Destination: %s\n", jedi4);
// 	return (0);
// }
