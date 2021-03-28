/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary_helper.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:59:22 by stfernan          #+#    #+#             */
/*   Updated: 2021/03/27 16:59:25 by stfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICTIONARY_HELPER_H
# define FT_DICTIONARY_HELPER_H

void	ft_cleanup_dict(char **g_small_dict, char **g_big_dict);
char	*ft_get_value(char *line);
int		ft_is_small_number(char *line);
int		ft_is_big_number(char *line);

#endif
