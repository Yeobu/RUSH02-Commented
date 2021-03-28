/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 10:07:31 by msainton          #+#    #+#             */
/*   Updated: 2021/03/28 14:15:31 by msainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

typedef struct	s_t_string{
	int		size;
	int		capacity;
	char	*data;
}				t_string;

t_string		ft_string_new();
//fonction calculate.c
char	*ft_complement(char *nbr);
int		ft_calculate_2(t_string *str, char *nbr);
int		ft_calculate_3(t_string *str, char *nbr);
int		ft_calculate_batches(t_string *str, char *nbr);
char	*ft_calculate(char *nbr);

//fonction dictionary.c
int		ft_load_line(char *line);
void	ft_load_lines(char *content, int size);
char	*ft_dictionary_load(char *filename);

//fonction dictionary_helper.c
void	ft_cleanup_dict(char **g_small_dict, char **g_big_dict);
char	*ft_get_value(char *line);
int		ft_is_small_number(char *line);
int		ft_is_big_number(char *line);

//fonction file.c
int		ft_file_size(char *filename);
char	*ft_read_file(char *filename, int *size);

//fonction string.c
void	ft_string_delete(t_string *str);
void	ft_string_append_char(t_string *str, char ch);
void	ft_string_append_str(t_string *str, char *chs);
int		ft_strlen(char *str);

//foction main.c
void	ft_putstr(char *s);
char	*load_dictionary(int argc, char **argv);
int		check_error(int argc, char **argv);
int		main(int argc, char **argv);
char	*ft_calculate(char *nbr);

char	*g_small_dict[101];
char	*g_big_dict[12];// le num max de characteres de valeur qu'on puisse trouver + 1 (undecillion = 11, +1 = 12);
#endif
