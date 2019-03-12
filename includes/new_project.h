/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 20:51:26 by amanuel           #+#    #+#             */
/*   Updated: 2018/12/31 03:51:17 by amanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"

typedef struct		s_s
{
	char			run;
	int			y_data;
	char			i_startend;
	int			i;
	int			j;
	int			k;
	int			l;
	int			m;
	int			n;
	int			solution;
	int			progress;
	int			ants;
	int			start;
	int			end;
	int			nbrooms;
	char			**data;
	char			**rooms;
	int			**pipes;
	char			*buff;
	int			*dawei;
	int			*path;
	int			**multipath;
	int			**print;
}					t_s;

//void				s_init(t_s *s);
//char				parsing(t_s *s, char **line);

#endif
