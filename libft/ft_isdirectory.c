/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdirectory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 20:54:16 by smishos           #+#    #+#             */
/*   Updated: 2024/08/21 21:11:38 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Function to check if the path is a directory
int ft_isdirectory(const char *path)
{
    int fd = open(path, O_RDONLY);
    if (fd == -1)
        return -1;
    char buffer;
    ssize_t result = read(fd, &buffer, 1);
    close(fd);
    if (result == -1 && errno == EISDIR)
        return 1;
    else if (result == -1)
        return -1;
    return 0;
}
