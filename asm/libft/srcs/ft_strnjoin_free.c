/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 18:58:20 by amanuel           #+#    #+#             */
/*   Updated: 2018/10/05 08:47:28 by amanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin_free(char *s1, char *s2, short i, char f)
{
	char	*s;
	char	*ret;
	char	*old;

	if (!s1 && !s2)
		return (0);
	if (!(s = malloc(i + 1)))
	{
		write(1, "Erreur malloc ft_strnjoin_free.c\n", 33);
		exit(-1);
	}
	ret = s;
	if (s1 && (old = s1))
		while (*old && i && i--)
			*s++ = *old++;
	if (s2 && (old = s2))
		while (*old && i && i--)
			*s++ = *old++;
	*s = 0;
	if (f && s1)
		free(s1);
	if (f && s2)
		free(s2);
	return (ret);
}
