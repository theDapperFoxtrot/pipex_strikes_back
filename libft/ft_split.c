/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:28:49 by smishos           #+#    #+#             */
/*   Updated: 2024/04/28 18:25:13 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_substrings(const char *str, char c)
{
	int	count;
	int	in_substring;

	count = 0; //counting the strings
	in_substring = 0; //a flag to determine if you're seeing characters other than the separator
	while (*str)
	{
		if (*str != c && in_substring == 0) //when the separator is found and flag is false
		{
			in_substring = 1;
			count++;
		}
		else if (*str == c)
			in_substring = 0; //when you discover the separator again, reset the flag to false
		str++;
	}
	return (count);
}

static char	*substring_create(const char *str, int start, int finish)
{
	char	*substr; //we're going to create each string in this function
	int		i;

	i = 0;
	substr = (char *)malloc((finish - start + 1) * sizeof(char)); //allocating memory for each
	if (!substr)
		return (NULL); //testing for successful allocation
	while (start < finish)
		substr[i++] = str[start++]; //and then copying the characters from the larger source string into the individual sub string array
	substr[i] = '\0'; //terminate the new substring with a null character
	return (substr); //and return it
}

static void	free_result_array(char **result, int j)
{
	while (j >= 0)
	{
		free(result[j]);
		result[j] = NULL;
		j--;
	}
	free(result);
	result = NULL;
}

static int	split_string(char const *s, char c, char **result, int count)
{
	size_t	i;
	int		j;
	int		index;
//
	i = 0;
	j = 0;
	index = -1;
	while (j < count)
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || !s[i]) && index >= 0)
		{
			result[j] = substring_create(s, index, i);
			if (!result[j])
			{
				free_result_array(result, j);
				return (1);
			}
			index = -1;
			j++;
		}
		i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	int		split_check;
	char	**result;

	if (!s)
		return (NULL); //if there's no string (empty and only a null character), return null
	count = count_substrings(s, c); //pass the string and separator
	result = (char **)malloc((count + 1) * sizeof(char *)); //malloc for an array of an array of characters
	if (!result)
		return (NULL); //if memory allocation fails, return null
	split_check = split_string(s, c, result, count); //pass all information to split_string
	if (split_check == 1)
	{
		return (NULL);
	}
	else
	{
		result[count] = NULL;
		return (result);
	}
}

// int main()
// {
// 	ft_split("Hey this is a test string", ' ');
// 	return (0);
// }
