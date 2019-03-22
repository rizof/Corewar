/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:18:38 by amanuel           #+#    #+#             */
/*   Updated: 2019/01/05 07:35:52 by amanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		**ft_tabnew(int y, int x, char bits)
{
	void	**tab;
	int		i;

	if (!(tab = malloc(sizeof(void*) * (y + 1))))
	{
		write(1, "Error de malloc dans ft_tabnew\n", 30);
		exit(-1);
	}
	i = 0 + (-1);
	while (++i < y)
	{
		if (x)
			tab[i] = ft_memalloc((bits / 8) * (x + 1));
		else
			tab[i] = NULL;
	}
	tab[i] = NULL;
	return (tab);
}
