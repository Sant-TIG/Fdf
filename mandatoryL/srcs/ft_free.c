/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:34:43 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/20 11:44:03 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	ft_free_list(t_str *str)
{
	t_str	*tmp;

	tmp = str;
	while (tmp)
	{
		tmp = tmp->next;
		free(str);
		str = tmp;
	}
}

void	ft_free_2d_str(char **str)
{
	ssize_t	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str[i]);
	free(str);
}