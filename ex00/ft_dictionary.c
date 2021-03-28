/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:56:49 by stfernan          #+#    #+#             */
/*   Updated: 2021/03/28 18:04:16 by stfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*g_small_dict[101];
char	*g_big_dict[12];

int		ft_load_line(char *line)
{
	char *value;

	value = ft_get_value(line);
	if (value == 0)
		return (0);
	if (0 <= ft_is_small_number(line))
		g_small_dict[ft_is_small_number(line)] = value;
	if (0 <= ft_is_big_number(line))
		g_big_dict[ft_is_big_number(line)] = value;
	return (1);
}

void	ft_load_lines(char *content, int size)
{
	int		i;
	char	*current_line;

	i = 0;
	current_line = content;
	while (i < size)
	{
		if (content[i] == '\n')
		{
			content[i] = '\0';
			ft_load_line(current_line);
			current_line = &content[i + 1];
		}
		i++;
	}
}

char	*ft_dictionary_load(char *filename)
{
	int		size;
	char	*content;

	content = ft_read_file(filename, &size);
	if (content == 0)
		return (0);
	ft_cleanup_dict(g_small_dict, g_big_dict);
	ft_load_lines(content, size);
	return (content);
}
