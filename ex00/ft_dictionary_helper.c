/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:57:05 by stfernan          #+#    #+#             */
/*   Updated: 2021/03/27 16:57:08 by stfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

char	*ft_get_value(char *line)// fonction de parsing
{
	int i;

	i = 0;
	while (line[i] != ':' && line[i] != '\0')//on avance tant qu'on a pas rencontre ":"
		i++;
	if (line[i] == '\0')//si on arrive a la fin d'une chaine on return par securite
		return (0);
	i++;
	while (line[i] == ' ')//on zaap les espaces pour arriver a la value
		i++;
	return (&line[i]);//on return un pointeur sur l'adresse du debut de la valeur
}

int		ft_is_small_number(char *line)
{
	int len;

	len = 0;
	while (line[len] >= '0' && line[len] <= '9')//on incremente tant qu'on a le nombre pour mesurer sa taille
		len++;
	if (len == 1)//si le nombre a une taille de 1 on le convertit (type atoi)
		return (line[0] - '0');
	if (len == 2)//si le nombre a une taille de 2 on le convertit en faisant comme atoi
		return ((line[0] - '0') * 10 + line[1] - '0');//On converti la dizaine en int (*10) pour avoir l'unite (index 1) que l'on convertit en int
	if (len == 3 && line[0] == '1' && line[1] == '0' && line[2] == '0')//si la taille est de 3 on return "betement" 3
		return (100);//on peut return direct 100
	return (-1);
}

int		ft_is_big_number(char *line)
{
	int len;
	int i;

	len = 0;
	while (line[len] >= '0' && line[len] <= '9')//on calcule la taille du chiffre
		len++;
	if (len % 3 != 1)//????????????????????????????????????????????????//
		return (-1);
	if (line[0] != '1')//
		return (-1);
	i = 1;
	while (i < len)
	{
		if (line[i] != '0')//tant qu'on a que des 0 c'est ok (le chiffre est dans le dico) si on a autre chose au milieu on return -1
			return (-1);
		i++;
	}
	return (len / 3 - 1); //????????????????????????
}
