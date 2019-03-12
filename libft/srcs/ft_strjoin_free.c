/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 18:58:20 by amanuel           #+#    #+#             */
/*   Updated: 2018/10/01 15:22:50 by amanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, char i, char j)
{
	char	*s;
	char	*ret;
	char	*old;

	if (!s1 && !s2)
		return (0);
	if (!(s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
	{
		write(1, "Erreur malloc ft_strjoin_free.c\n", 32);
		exit(-1);
	}
	ret = s;
	if (s1 && (old = s1))
		while (*old)
			*s++ = *old++;
	if (s2 && (old = s2))
		while (*old)
			*s++ = *old++;
	*s = 0;
	if (i && s1)
		free(s1);
	if (j && s2)
		free(s2);
	return (ret);
}
