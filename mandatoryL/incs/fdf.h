/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:34:34 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/20 14:10:07 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_str
{
	char			c;
	struct s_str	*next;
}	t_str;

/* FDF FUNCTIONS */
void	ft_get_map(int fd);

/* FREE FUNCTIONS */
void	ft_free_list(t_str *str);
void	ft_free_2d_str(char **str);

/* LINKED FUNCTIONS */
void	ft_insert_end_char(char c, t_str **str);
void	ft_insert_empty_char(char c, t_str **str);

/* PRINT FUNCTIONS */
void	ft_print_list(t_str *str);
void	ft_print_2d_str(char **str);

/* 	STRING FUNCTIONs */
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strndup(const char *str, size_t len);
char	**ft_split(const char *str, char c);

#endif
