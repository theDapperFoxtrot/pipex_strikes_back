/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:30:34 by smishos           #+#    #+#             */
/*   Updated: 2024/08/21 18:55:28 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0) //if the number is 0 we return 1, because we will still write the character 0 follow by a null character '\0'
		return (1);
	while (n != 0)
	{
		n /= 10; //we divide the number by 10, incrementing count each time to know how many index positions as needed to write the number
		count++;
	}
	return (count);
}

static void	convert_integer(long num, char *str, int i)
{
	while (i-- > 0)
	{
		str[i] = (num % 10) + '0'; //conversion of the int to character (+ 48)
		num /= 10; //after each character is assigned, we "shave off" the last digit, essentially working backwards
	}
}

char	*ft_itoa(int n)
{
	int		negative;
	int		digits;
	char	*str;
	int		i;
	long	num;

	num = (long)n; //type cast the number into long while working with it, this solves min_int overflow
	negative = 0; //initiate as 0 (false)
	if (num < 0) //if number is less than 0, negative flag becomes 1 (true), multiply number to be positive
	{
		negative = 1;
		num = -num;
	}
	digits = count_digits(n); //count the digits
	i = digits + negative; //we get the number of digits, and either + 0 or 1 whether or not there's a hyphen
	str = (char *)malloc(sizeof(char) * (i + 1)); //allocate memory for all the characters including the null terminator
	if (!str)
		return (NULL); //if allocation fails, return null
	str[i] = '\0';
	convert_integer(num, str, i); //this will assign the digits to their correct index position in the string, using i to count down
	if (negative)
		str[0] = '-'; //if the number is negative, then write a hyphen to the first index position
	return (str); //return the string
}

// #include <stdio.h>

// int main()
// {
//     char    *result = ft_itoa(0);
//     printf("String output: %s\n", result);
//     return (0);
// }