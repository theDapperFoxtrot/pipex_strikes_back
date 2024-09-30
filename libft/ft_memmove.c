/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:32:04 by smishos           #+#    #+#             */
/*   Updated: 2024/08/09 13:42:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;
	// typically I have been creating variables that type cast the received parameters, but I noticed that it can be achieved without the need to make variables
	//if both are empty, return null
	if (!dst && !src)
		return (0);
	//if dest begins after source, start from the end of the source and work backwards to preserve all the data
	if (dst > src)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			*(char *)(dst + i) = *(char *)(src + i); //so here we're type casting and derefrencing the pointer
			i--;
		}
	}
	//the only other case is where the dest is before the source, so you can safely copy data without loss
	else
	{
		i = 0;
		while (i < (int)len)
		{
			*(char *)(dst + i) = *(char *)(src + i); //in the other case we're dereferencing the type casted index
			i++;
		}
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h> // For memcmp
// #include <stdlib.h> // For malloc

// // Test function
// int main()
// {
// 	// Test case 1: Copying from lower address to higher address
// 	char src1[] = "abcdef";
// 	char dst1[10];
// 	ft_memmove(dst1, src1, 6);
// 	printf("Test Case 1 Result: %s (Expected: %s)\n", memcmp(dst1, src1, 6), src1);

// 	// Test case 2: Copying from higher address to lower address
// 	char src2[] = "abcdef";
// 	char dst2[10];
// 	ft_memmove(dst2 + 3, src2, 6);
// 	printf("Test Case 2 Result: %s (Expected: %s)\n", memcmp(dst2 + 3, src2, 6), src2);

// 	// Test case 3: Overlapping region, dst overlaps with src
// 	char src3[] = "abcdefghij";
// 	ft_memmove(src3 + 3, src3, 7);
// 	printf("Test Case 3 Result: %s (Expected: %s)\n", memcmp(src3 + 3, src3, 7), src3);

// 	// Test case 4: Overlapping region, src overlaps with dst
// 	char src4[] = "abcdefghij";
// 	ft_memmove(src4, src4 + 3, 7);
// 	printf("Test Case 4 Result: %s (Expected: %s)\n", memcmp(src4, src4 + 3, 7), src4 + 3);

// 	// Test case 5: Copying empty string
// 	char src5[] = "";
// 	char dst5[10] = "test";
// 	ft_memmove(dst5, src5, 0);
// 	printf("Test Case 5 Result: %s (Expected: %s)\n", memcmp(dst5, "test", 4), "test");

// 	return 0;
// }