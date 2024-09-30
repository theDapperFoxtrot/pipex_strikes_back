/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:55:09 by smishos           #+#    #+#             */
/*   Updated: 2024/04/27 15:52:38 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// compare two strings until n is reached or there is a difference -
// if same, return 0, otherwise show the "distance" from each
// char on ascii table
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		else
			i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int	main()
// {
// 	char	jedi [12] = "Hello there";
// 	char	jedi2 [12] = "Heälo there";

// 	printf("Standard: %d\n", strncmp(jedi, jedi2, 3));
// 	printf("Mine: %d\n", ft_strncmp(jedi, jedi2, 3));
// 	return (0);
// }