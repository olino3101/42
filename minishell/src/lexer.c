/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:38:48 by fcornill          #+#    #+#             */
/*   Updated: 2024/07/15 13:40:03 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void search_quotation(char **s, char *end)
{
	if (**s == '\'' || **s == '\"')
	{
		(*s)++;
		while (*s < end && **s != '\'' && **s != '\"') // chercher la fin de la citation
            (*s)++;
        if (*s < end && (**s == '\'' || **s == '\"')) // si la fin de la citation est trouvée
            (*s)++;
	}
}

static bool redirection_operator_process(char **s, int *ret, char chr)
{
	if (**s == chr)
	{
		(*s)++;
		if (**s == chr)
		{
			if (chr == '<')
				*ret = '-';
			else
				*ret = '+';
			(*s)++;
		}
		return (true);
	}
	return (false);
}


static void redirection_operator(char **s, int *ret, char *end, char *sep)
{
	if (**s == '|')
		s++;
	else if (redirection_operator_process(s, ret, '>') || redirection_operator_process(s, ret, '<'))
		return ;
	else
	{
		*ret = 'a';
		while (*s < end && !ft_strchr(" \n\t", **s) && !ft_strchr(sep, **s))
			(*s)++;
	}
}

int	ft_add_token(char **begin, char *end, char **cur, char **end_cur)
{
	char	sep[] = "<|>";
	char	*s;
	int		ret;

	s = *begin;
	while (s < end && ft_strchr(" \n\t", *s))
		s++;
	if (cur)
		*cur = s;
	ret = *s;
	if (*s == 0)
		return (ret);
	search_quotation(&s, end);
	redirection_operator(&s, &ret, end, sep);
	if (end_cur)
		*end_cur = s;
	while (s < end && ft_strchr(" \n\t", *s))
		s++;
	*begin = s;
	return (ret);
}


