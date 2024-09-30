/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:46:22 by smishos           #+#    #+#             */
/*   Updated: 2024/04/27 15:30:05 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// find the first occurence of the character (c)
// return the string from that character
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(&s[i]));
		i++;
	}
	// if you search for null, return null at end of string
	if ((char)c == 0)
		return ((char *)(&s[i]));
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char	jedi [12] = "Hello there";

// 	printf("%s - %s", strchr(jedi, 0), ft_strchr(jedi, 0));
// 	return (0);
// }