/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:00:54 by smishos           #+#    #+#             */
/*   Updated: 2024/04/27 15:54:13 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;

	n_len = ft_strlen(needle);
	if (needle == NULL || n_len == 0)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (*haystack && len >= n_len)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle, n_len) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	if (*needle == '\0')
		return ((char *)haystack);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int main() {
//     const char *haystack = "Hello, world!";
//     const char *needle1 = "world";
//     const char *needle2 = "lo";
//     const char *needle3 = "abc";
//     size_t len = strlen(haystack);

//     printf("Testing ft_strnstr:\n");

//     printf("Needle: \"%s\", Found at: \"%s\"\n", needle1, ft_strnstr(haystack, needle1, len));
//     printf("Needle: \"%s\", Found at: \"%s\"\n", needle2, ft_strnstr(haystack, needle2, len));
//     printf("Needle: \"%s\", Found at: \"%s\"\n", needle3, ft_strnstr(haystack, needle3, len));

//     return 0;
// }
