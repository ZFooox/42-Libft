/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocroon <jocroon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:41:02 by jocroon           #+#    #+#             */
/*   Updated: 2024/10/22 15:46:54 by jocroon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>

int main(void)
{
    char src[] = "Campus 19";
    char dest[20];

    printf("Avant ft_memcpy:\n");
    printf("Source: %s\n", src);
    printf("Destination: %s\n", dest);

    ft_memcpy(dest, src, sizeof(src));

    printf("Après ft_memcpy:\n");
    printf("Source: %s\n", src);
    printf("Destination: %s\n", dest);

    return 0;
}
*/