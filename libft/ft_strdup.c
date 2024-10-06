/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:47:48 by smishos           #+#    #+#             */
/*   Updated: 2024/10/06 18:38:17 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strdup(const char *src)
{
    char    *dup;
    size_t    i;

    i = 0;
    dup = (char *)malloc(sizeof(*src) * (ft_strlen(src) + 1));
    if (!dup)
        return (NULL);
    while (src[i])
    {
        dup[i] = src[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
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