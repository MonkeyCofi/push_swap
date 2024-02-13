/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:52:28 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/13 12:22:48 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	words;
	int	letters;
	int	i;

	i = 0;
	words = 0;
	letters = 0;
	while (s[i])
	{
		if (s[i] != c)
			letters++;
		else if (s[i] == c && letters)
		{
			letters = 0;
			words++;
		}
		if (s[i + 1] == '\0' && s[i] != c)
			words++;
		i++;
	}
	return (words);
}

static int	get_length(const char *s, char c)
{
	int	length;

	length = 0;
	while (*s != '\0' && *s != c)
	{
		length++;
		s++;
	}
	return (length);
}

static void	add_words(char **words, char *s, char c)
{
	char	*word;
	int		current_word;
	int		i;

	current_word = 0;
	while (*s)
	{
		i = 0;
		if (*s != c)
		{
			word = (char *)malloc(sizeof(char) * (get_length(s, c) + 1));
			if (!word)
				return ;
			while (*s != c && *s)
				word[i++] = *s++;
			word[i] = '\0';
			words[current_word++] = ft_strdup(word);
			free(word);
		}
		else
			s++;
	}
	words[current_word] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	words = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!words)
		return (NULL);
	add_words(words, (char *)s, c);
	return (words);
}








/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:52:28 by pipolint          #+#    #+#             */
/*   Updated: 2023/11/12 13:51:29 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"

//static int	is_separator(char *set, char c)
//{
//	int	i;

//	i = 0;
//	while (set[i])
//	{
//		if (c == set[i])
//			return (1);
//		i++;
//	}
//	return (0);
//}

//static int	count_words(char const *s, char *c)
//{
//	int	words;
//	int	letters;
//	int	i;

//	i = 0;
//	words = 0;
//	letters = 0;
//	while (s[i])
//	{
//		if (!is_separator(c, s[i]))
//			letters++;
//		//else if (s[i] == c && letters)
//		else if (is_separator(c, s[i]) && letters)
//		{
//			letters = 0;
//			words++;
//		}
//		//if (s[i + 1] == '\0' && s[i] != c)
//		if (is_separator(c, s[i + 1]) && !is_separator(c, s[i]))
//			words++;
//		i++;
//	}
//	return (words);
//}

//static int	get_length(char *s, char *c)
//{
//	int	length;

//	length = 0;
//	while (*s != '\0' && !is_separator(c, *s))
//	{
//		length++;
//		s++;
//	}
//	return (length);
//}

//static void	add_words(char **words, char *s, char *set)
//{
//	char	*word;
//	int		current_word;
//	int		i;

//	current_word = 0;
//	while (*s)
//	{
//		i = 0;
//		if (!is_separator(set, *s))
//		{
//			word = malloc(sizeof(char) * (get_length(s, set)) + 1);
//			if (!word)
//				return ;
//			while (!is_separator(set, *s) && *s)
//				word[i++] = *s++;
//			word[i] = '\0';
//			words[current_word++] = ft_strdup(word);
//			if (!words[current_word - 1])
//				return ;
//			free(word);
//		}
//		else
//			s++;
//	}
//	words[current_word] = 0;
//}

//char	**ft_split(char const *s, char *set)
//{
//	char	**words;
//	int		word_count;

//	if (!s)
//		return (NULL);
//	word_count = count_words(s, set);
//	words = (char **)malloc(sizeof(char *) * (word_count + 1));
//	if (!words)
//		return (NULL);
//	add_words(words, (char *)s, set);
//	return (words);
//}
