/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:15:33 by smishos           #+#    #+#             */
/*   Updated: 2024/08/21 18:56:28 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	if (dstsize == 0)
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	j = dst_len;
	if (dst_len < dstsize - 1 && dstsize > 0)
	{
		while (src[i] && dst_len + i < dstsize - 1)
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = '\0';
	}
	if (dst_len >= dstsize)
		dst_len = dstsize;
	return (dst_len + src_len);
}

// #include <stdio.h>

// int main ()
// {
// 	char dest0 [11] = "Hello";
// 	const char *src0 = "World";
// 	// size_t result0 = 
// 	ft_strlcat(dest0, src0, 11);
// 	// Check the content of dest0 and result0
// 	printf("Destination: %s - Source: %s\n", dest0, src0);

// 	// char dest1[20] = "Hello";
// 	// const char *src1 = "This is a large source string";
// 	// size_t result1 = ft_strlcat(dest1, src1, 20);
// 	// // Check the content of dest1 and result1

// 	// char dest2[10] = "Hello";
// 	// const char *src2 = "";
// 	// size_t result2 = ft_strlcat(dest2, src2, 10);
// 	// // Check the content of dest2 and result2

// 	// char *dest3 = NULL;
// 	// const char *src3 = "World";
// 	// size_t result3 = ft_strlcat(dest3, src3, 0);
// 	// // Check the result3 (should be the length of src)

// 	// char dest4[10] = "Hello";
// 	// const char *src4 = "World";
// 	// size_t result4 = ft_strlcat(dest4, src4, 0);
// 	// // Check the result4 (should be the length of src)

// 	// char dest5[10] = "Hello";
// 	// const char *src5 = "World";
// 	// size_t result5 = ft_strlcat(dest5, src5, 15);
// 	// // Check the content of dest5 and result5

// 	// char dest6[5] = "Hello";
// 	// const char *src6 = "World";
// 	// size_t result6 = ft_strlcat(dest6, src6, 5);
// 	// // Check the content of dest6 and result6

// 	// char dest7[5] = "Hello";
// 	// const char *src7 = "World";
// 	// size_t result7 = ft_strlcat(dest7, src7, 10);
// 	// // Check the content of dest7 and result7

// }
