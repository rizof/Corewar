/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 21:00:33 by amanuel           #+#    #+#             */
/*   Updated: 2018/10/01 15:18:17 by amanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(char *s1, short i)
{
	char	*s;
	short	j;

	s = NULL;
	if (s1)
	{
		if (!(s = malloc(i + 1)))
		{
			write(1, "Erreur malloc strndup\n", 25);
			exit(-1);
		}
	}
	j = 0 + (-1);
	if (s && s1)
		while (s1[++j] && i--)
			s[j] = s1[j];
	s[j] = 0;
	return (s);
}
