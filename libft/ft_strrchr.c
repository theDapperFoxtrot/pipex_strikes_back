/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:03:13 by smishos           #+#    #+#             */
/*   Updated: 2024/04/27 15:54:20 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// locate the LAST occurence of specified character in string
// return the string from that character
char	*ft_strrchr(const char *s, int c)
{
	char	*end; //a variable to preserve the original point position of string (s)
	char	find; //a variable to seek the character (c)
	size_t	i;

	end = (char *)s;
	find = (char)c;
	i = ft_strlen(s); //find the end of the string (the last character that isn't a null character)
	while (i > 0)
	{
		// start at the end and work backwards until the first occurence of the character
		if (end[i] == find)
			return (end + i);
		i--;
	}
	if (end [i] == find)
		return (end);
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char	jedi [12] = "Hello there";

// 	printf("%s - %s", strrchr(jedi, 'h'), ft_strrchr(jedi, 'h'));
// 	return (0);
// }
