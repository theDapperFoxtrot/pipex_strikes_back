/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:45:02 by smishos           #+#    #+#             */
/*   Updated: 2024/05/02 16:55:54 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//allocate memory for the requested size and initialize each byte to zero
//return a pointer to the start of the allocated memory block
void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*ptr;

	//if either count or size is zero, allocate memory for 1 element of size 1
	if (!count && !size)
		return (ft_calloc(1, 1));
	total_size = count * size; //calculate the total size of the memory block
	//check for potential overflow or exceeding maximum size
	if ((count != 0 && total_size / count != size) || total_size > 2147483648)
		return (NULL);
	ptr = malloc(total_size); //allocate memory according to the calculated size
	if (!ptr)
		return (NULL); //checking for successful allocation
	if (ptr)
		ft_memset(ptr, 0, total_size); //set memory with default value of zero according to size
	return (ptr); //return pointer allocated memory block
}

//ensure you cc with this file, ft_memset.c as well as a custom main called main_for_calloc.c