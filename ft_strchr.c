/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocroon <jocroon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:28:06 by jocroon           #+#    #+#             */
/*   Updated: 2024/11/02 12:08:25 by jocroon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//pour rechercher un caractère dans une chaîne en commençant par le début
char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;
	char			d;

	i = 0;
	d = (char) c;
	while (str[i])
	{
		if (str[i] == d)
			return ((char *) &str[i]);
		i++;
	}
	if (str[i] == d)
		return ((char *) &str[i]);
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char str[] = "Hello, World!";
	int	c = 'd';

	printf("%s\n", ft_strchr(str, c));
	return (0);
}
*/