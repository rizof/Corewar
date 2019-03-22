/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 03:28:45 by amanuel           #+#    #+#             */
/*   Updated: 2018/10/05 08:30:24 by amanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strins_free(char *s1, char *s2, short i, char f)
{
	char		*fresh;

	fresh = ft_strndup(s1, i);
	fresh = ft_strjoin_free(fresh, s2, f, f);
	fresh = ft_strjoin_free(fresh, s1 + i, f, 0);
	if (f && s1)
		free(s1);
	return (fresh);
}
