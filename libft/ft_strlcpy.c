/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:07:33 by smishos           #+#    #+#             */
/*   Updated: 2024/04/23 12:21:32 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (i < src_len && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Define a simple test function
void test_ft_strlcpy(char *dst, const char *src, size_t dstsize) {
    size_t result = ft_strlcpy(dst, src, dstsize);
    printf("Source: \"%s\", Destination: \"%s\", dstsize: %zu\n", src, dst, dstsize);
    printf("Result: %zu, Destination after copy: \"%s\"\n", result, dst);
    printf("-------------------------------\n");
}

int main() {
    char dest[20];
    const char *src = "Hello, world!";
    
    // Test cases
    test_ft_strlcpy(dest, src, 20);  // Test with dstsize larger than src
    test_ft_strlcpy(dest, src, 5);   // Test with dstsize smaller than src
    test_ft_strlcpy(dest, src, 0);   // Test with dstsize of 0
    test_ft_strlcpy(dest, "", 10);   // Test with empty src string
    test_ft_strlcpy(dest, src, 15);  // Test with dstsize larger than src but smaller than src length
    
    return 0;
}