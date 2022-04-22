/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_empty_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:35:05 by sperez-p          #+#    #+#             */
/*   Updated: 2022/04/20 11:35:06 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	ft_insert_empty_char(char c, t_str **str)
{
	t_str	*new;

	new = (t_str *)malloc(sizeof(t_str));
	if (!new)
		return ;
	new->c = c;
	new->next = NULL;
	*str = new;
}
