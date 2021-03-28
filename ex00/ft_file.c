/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:58:08 by stfernan          #+#    #+#             */
/*   Updated: 2021/03/28 18:09:25 by stfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft.h"

int		ft_file_size(char *filename)
{
	int		size;
	int		fd;
	char	ch;

	size = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (read(fd, &ch, 1) > 0)
		size++;
	close(fd);
	return (size);
}

char	*ft_read_file(char *filename, int *size)
{
	int		fd;
	char	*content;

	*size = ft_file_size(filename);
	if (*size == -1)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!(content = malloc(*size + 1)))
		return (0);
	read(fd, content, *size);
	close(fd);
	content[*size] = '\n';
	return (content);
}
