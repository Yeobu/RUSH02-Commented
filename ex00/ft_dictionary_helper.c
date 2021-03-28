/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:57:05 by stfernan          #+#    #+#             */
/*   Updated: 2021/03/28 18:14:36 by stfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_cleanup_dict(char **g_small_dict, char **g_big_dict)
{
	int i;

	i = 0;
	while (i <= 101)
	{
		g_small_dict[i] = 0;
		i++;
	}
	i = 0;
	while (i < 12)
	{
		g_big_dict[i] = 0;
		i++;
	}
}

char	*ft_get_value(char *line)
{
	int i;

	i = 0;
	while (line[i] != ':' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (0);
	i++;
	while (line[i] == ' ')
		i++;
	return (&line[i]);
}

int		ft_is_small_number(char *line)
{
	int len;

	len = 0;
	while (line[len] >= '0' && line[len] <= '9')
		len++;
	if (len == 1)
		return (line[0] - '0');
	if (len == 2)
		return ((line[0] - '0') * 10 + line[1] - '0');
	if (len == 3 && line[0] == '1' && line[1] == '0' && line[2] == '0')
		return (100);
	return (-1);
}

int		ft_is_big_number(char *line)
{
	int len;
	int i;

	len = 0;
	while (line[len] >= '0' && line[len] <= '9')
		len++;
	if (len % 3 != 1)
		return (-1);
	if (line[0] != '1')
		return (-1);
	i = 1;
	while (i < len)
	{
		if (line[i] != '0')
			return (-1);
		i++;
	}
	return (len / 3 - 1);
}
