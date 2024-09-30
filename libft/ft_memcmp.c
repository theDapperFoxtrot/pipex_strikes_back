/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:18:19 by smishos           #+#    #+#             */
/*   Updated: 2024/08/09 13:42:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//very similar to string compare, but you know that 2 strings exist, and provide how far in memory to check (size_t n)
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *) s1;
	ptr2 = (unsigned char *) s2;
	while (n-- > 0)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		else
		{
			ptr1++;
			ptr2++;
		}
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char jedi[] = "Hello therex";
// 	char jedi2[] = "Hello there";

// 	printf("%d\n", ft_memcmp(jedi, jedi2, 12));
// 	printf("%d\n", memcmp(jedi, jedi2, 12));
// 	return (0);
// }
