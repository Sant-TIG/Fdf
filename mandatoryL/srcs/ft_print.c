/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:42:47 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/20 11:42:48 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	ft_print_list(t_str *str)
{
	while (str)
	{
		printf("%c", str->c);
		str = str->next;
	}
}

void	ft_print_2d_str(char **str)
{
	ssize_t	i;

	i = -1;
	while (str[++i])
		printf("%s\n", str[i]);
}
