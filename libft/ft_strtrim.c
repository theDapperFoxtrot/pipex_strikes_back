/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:26:18 by smishos           #+#    #+#             */
/*   Updated: 2024/04/27 15:57:01 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	len = end - start;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, s1 + start, len);
	result[len] = '\0';
	return (result);
}

// #include "libft.h"
// #include <stdio.h>

// int main() {
//     const char *s1 = "   Hello, world!   ";
//     const char *set = " ";
//     char *trimmed = ft_strtrim(s1, set);
    
//     if (trimmed) {
//         printf("Original string: \"%s\"\n", s1);
//         printf("Trimmed string: \"%s\"\n", trimmed);
//         free(trimmed);
//     } else {
//         printf("Error: Unable to allocate memory.\n");
//     }
    
//     return 0;
// }
