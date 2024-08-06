/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yashevch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:31:20 by yashevch          #+#    #+#             */
/*   Updated: 2024/03/08 16:23:06 by yashevch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	**free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

int	ft_count_elements(char const *s, char c)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			counter++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (counter);
}

static void	ft_copy_word(char *dest, char const *s, int i, int word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		dest[j] = s[i - word_len];
		j++;
		word_len--;
	}
	dest[j] = '\0';
}

static char	**ft_split_words(char **dest, char const *s, char c, int num_words)
{
	int	i;
	int	word;
	int	word_len;

	i = 0;
	word = 0;
	word_len = 0;
	while (word < num_words)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			word_len++;
		}
		dest[word] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!dest)
			return (free_array(dest, word));
		ft_copy_word(dest[word], s, i, word_len);
		word_len = 0;
		word++;
	}
	dest[word] = 0;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		len;

	len = ft_count_elements(s, c);
	dest = (char **)malloc(sizeof(char *) * (len + 1));
	if (!dest)
		return (NULL);
	dest = ft_split_words(dest, s, c, len);
	return (dest);
}
