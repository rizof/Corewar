/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 04:56:39 by amanuel           #+#    #+#             */
/*   Updated: 2018/10/01 15:12:36 by amanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_reverse_int(int i)
{
	char		src[4];
	char		ret[4];
	int8_t		j;

	*(int*)src = i;
	j = 0 + (-1);
	while (++j < 4)
		ret[j] = src[3 - j];
	i = *(int*)ret;
	return (i);
}
