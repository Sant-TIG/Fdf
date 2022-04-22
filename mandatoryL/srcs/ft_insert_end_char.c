/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_end_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:42:30 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/20 11:42:31 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	ft_insert_end_char(char c, t_str **str)
{
	t_str	*tmp;
	t_str	*new;

	tmp = *str;
	if (!*str)
	{
		ft_insert_empty_char(c, str);
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	new = (t_str *)malloc(sizeof(t_str));
	if (!new)
		return ;
	new->c = c;
	new->next = NULL;
	tmp->next = new;
}
