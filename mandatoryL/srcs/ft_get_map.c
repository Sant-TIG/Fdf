/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:34:56 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/20 14:45:59 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

static void	ft_check_len_map(char **map, char *tmp_map, t_str *str)
{
	ssize_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	i = -1;
	j = 0;
	len1 = 0;
	while (map[0][j] && ++len1)
		j++;
	while (map[++i])
	{
		j = 0;
		len2 = 0;
		while (map[i][j] && ++len2)
			j++;
		if (len1 != len2)
		{
			ft_free_list(str);
			free(tmp_map);
			ft_free_2d_str(map);
			printf("Invalid map (error len)\n");
			exit (1);
		}
	}
}

static void	ft_check_digit_map(char **map, char *tmp_map, t_str *str)
{
	ssize_t	i;
	size_t	j;

	i = -1;
	while (map[++i])
	{
		j = 0;
		while (ft_isdigit(map[i][j]))
			j++;
		if (map[i][j] != '\0')
		{
			ft_free_list(str);
			free(tmp_map);
			ft_free_2d_str(map);
			printf("Invalid map(digit error)\n");
			exit (1);
		}
	}
}

static char	*ft_read_map(int fd, t_str **str)
{
	char	c;
	char	*tmp_map;
	size_t	len;
	t_str	*tmp;
	ssize_t	i;

	i = -1;
	len = 1;
	while (read(fd, &c, 1) != 0 && ++len)
		ft_insert_end_char(c, str);
	tmp_map = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp_map)
		return (NULL);
	tmp = *str;
	while (tmp)
	{
		tmp_map[++i] = tmp->c;
		tmp = tmp->next;
	}
	tmp_map[++i] = '\0';
	if (!*tmp_map)
	{
		ft_free_list(*str);
		free(tmp_map);
		printf("Invalid map (Empty map)\n");
		exit (1);
	}
	return (tmp_map);
}

void	ft_get_map(int fd)
{
	char	*tmp_map;
	t_str	*str;
	char	**char_map;
	int		**int_map;

	str = NULL;
	if (fd == -1)
	{
		perror("");
		exit (1);
	}
	tmp_map = ft_read_map(fd, &str);
	char_map = ft_split(tmp_map, '\n');
	ft_check_digit_map(char_map, tmp_map, str);
	ft_check_len_map(char_map, tmp_map, str);
	ft_print_2d_str(char_map);
	int_map = (int **)malloc(sizeof(int *) * )//necesito saber la cantidad de filas del mapa
	ft_free_list(str);
	free(tmp_map);
	ft_free_2d_str(char_map);
}
