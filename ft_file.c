/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:58:08 by stfernan          #+#    #+#             */
/*   Updated: 2021/03/27 16:58:09 by stfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_file_size(char *filename)
{
	int		size;
	int		fd;
	char	ch;

	size = 0;
	fd = open(filename, O_RDONLY);//commande pour open le fichier
	if (fd == -1)
		return (-1);//si open a rate il renvoie -1, on return -1 pour savoir qu'un pb a eu lieu
	while (read(fd, &ch, 1) > 0)//boucle pour calculer le nombre d'octet a lire. Read renvoie 0 auand il arrive en fin de fichier, on peut ce servir de ca pr calculer
		size++;
	close(fd);//on ferme le fichier
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
	if(!(content = malloc(*size + 1)))
		return (0);
	read(fd, content, *size);//on lit le fichier, read prend comme parametre le fd, un buffer de destination et le nb d'octet a lire
	close(fd);//on ferme le fichier
	content[*size] = '\n';
	return (content);
}
