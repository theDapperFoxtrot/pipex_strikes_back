/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:47:48 by smishos           #+#    #+#             */
/*   Updated: 2024/04/27 15:58:44 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// duplicate the string, allocating space for it memory
char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*new_str;
// find the length of the source, allocate the memory given the size of the string
	len = ft_strlen(s);
	new_str = (char *)ft_calloc(len + 1, sizeof(char));
// test if the allocation is successful, and if so, you can copy the source to dest
	if (new_str)
		ft_memcpy(new_str, s, len);
	return (new_str);
}

// you will need a custom main for this, and exclude the main from ft_memcpy.c
// then you can compile the three files together for testing

// #include <stdio.h>

// int main()
// {
// 	char *str1 = ft_strdup("");
// 	printf("%s\n", str1);
// 	free(str1);
// 	return (0);
// }

// you can check for leaks with "leaks --atExit -- ./a.out"