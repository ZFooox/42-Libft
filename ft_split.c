/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocroon <jocroon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:14:18 by jocroon           #+#    #+#             */
/*   Updated: 2024/11/04 15:36:44 by jocroon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// sert à diviser un tableau en plusieurs autres tableaux 
// dés que le séparateur est trouvé

// pour compter les mots
static int	word_counter(const char *str, char sep)
{
	int	count;
	int	is_word;
	int	i;

	if (!str)
		return (0);
	count = 0;
	is_word = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != sep && is_word == 0)
		{
			is_word = 1;
			count++;
		}
		else if (str[i] == sep)
			is_word = 0;
		i++;
	}
	return (count);
}

// pour allouer la mémoire pour les mots
static char	*word_alloc(const char *start, const char *end)
{
	char	*word;
	int		i;

	if (!start || !end)
		return (NULL);
	i = 0;
	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = *start++;
	word[i] = '\0';
	return (word);
}

// initialise le tableau de résultats
static char	**init_result(char const *str, char sep)
{
	char	**result;

	if (!str)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (word_counter(str, sep) + 1));
	if (!result)
		return (NULL);
	return (result);
}

//remplir le tableaux de résultats
//si return -1 -> ok et si autre -> échec
static int	fill_result(char **result, char const *str, char sep)
{
	int		tab_index;
	char	*new_word;

	if (!result || !str)
		return (0);
	tab_index = 0;
	while (*str)
	{
		if (*str != sep)
		{
			new_word = (char *)str;
			while (*str && *str != sep)
				str++;
			result[tab_index] = word_alloc(new_word, str);
			if (!result[tab_index])
				return (tab_index);
			tab_index++;
		}
		else
			str++;
	}
	result[tab_index] = NULL;
	return (-1);
}

//fonction principale
char	**ft_split(char const *str, char sep)
{
	char	**result;
	int		i;

	if (!str)
		return (NULL);
	result = init_result(str, sep);
	if (!result)
		return (NULL);
	i = fill_result(result, str, sep);
	if (i != -1)
	{
		while (i >= 0)
			free(result[i--]);
		free(result);
		return (NULL);
	}
	return (result);
}

/* #include <stdio.h>

int	main(void)
{
	char	**result;
	int		i;

	result = ft_split("I!love!campus!19", '!');
	i = 0;
	
	if (!result[i])
	{
		printf("ERREUR");
		return (1);
	}
	while (result[i])
	{
		printf("Mot %d: %s\n", i, result[i]);
		i++;
	}
	return (0);
} */