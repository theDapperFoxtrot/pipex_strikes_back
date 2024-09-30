/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:17:22 by smishos           #+#    #+#             */
/*   Updated: 2024/08/21 18:54:43 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
	return ;
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     // Test 1: Zero out a string
//     char str1[] = "Hello, world!";
//     size_t len1 = strlen(str1);
//     printf("Before ft_bzero: %s\n", str1);
//     ft_bzero(str1, len1);
//     printf("After ft_bzero: %s\n", str1);

//     // Test 2: Zero out an array of integers
// 	size_t i = 0;
//     int nums[] = {1, 2, 3, 4, 5};
//     size_t num_count = sizeof(nums) / sizeof(nums[0]);
//     printf("Before ft_bzero: ");
//     while (i < num_count)
//     {
//         printf("%d ", nums[i]);
// 		i++;
//     }
//     printf("\n");
//     ft_bzero(nums, sizeof(nums));
// 	i = 0;
//     printf("After ft_bzero: ");
//     while (i < num_count)
//     {
//         printf("%d ", nums[i]);
// 		i++;
//     }
//     printf("\n");

//     return 0;
// }