/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:56:45 by sfreitas          #+#    #+#             */
/*   Updated: 2020/04/29 22:57:17 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cleanline(char **line, char *s_line)
{
	char	*l_temp;
	int		pos;
	pos = newline(s_line);
	if (pos >= 0)
	{
		s_line[pos] = '\0';
		*line = (char*)calloc(ft_strlen(s_line) + 1, sizeof(char));
		l_temp = (char*)calloc(ft_strlen(&s_line[pos + 1]) + 1, sizeof(char));
		ft_strlcpy(*line, s_line, ft_strlen(s_line) + 1);
		ft_strlcpy(l_temp, &s_line[pos + 1], ft_strlen(&s_line[pos + 1]) + 1);
		free(s_line);
		s_line = NULL;
		return (l_temp);
	}
	*line = (char*)calloc(ft_strlen(s_line) + 1, sizeof(char));
	ft_strlcpy(*line, s_line, ft_strlen(s_line) + 1);
	free(s_line);
	s_line = NULL;
	return (s_line);
}


void	ft_bzero(char *source)
{
	int i;

	i = 0;
	if (source)
	{
		while (i < BUFFER_SIZE)
		{
			source[i] = '\0';
			i++;
		}
	}
}


int		newline(char *s_line)
{
	int i;
	int pos;
	i = 0;
	pos = -1;
	if (s_line)
	{
		while (s_line[i])
		{
			if (s_line[i] == '\n' && pos == -1)
			{
			 	pos = i;
			 	return(pos);
			}
			i++;
		}
	}
	return (pos);
}

/* Função responsável por contar caracteres na string.                        */
size_t		ft_strlen(const char *source)
{
	int i;

	i = 0;
	if (source)
	{
		while (source[i] != '\0')
			i++;
	}
	return (i);
}
