/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 20:51:26 by amanuel           #+#    #+#             */
/*   Updated: 2018/12/31 03:51:17 by amanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../libft/includes/libft.h"

typedef struct			s_asm
{
	char			*file_name;
	int			file_name_size;

	char			binary_init;
	char			binary_name;
	char			binary_comment;
	char			binary_instruction;
	char			*p;
	char			*tmp;
	int			n;
	int			i;

	char			error;
	int			y;
	int			x;

	int			fd;
	char			*line;

	struct s_list		*first_binary_part;
	struct s_list		*binary_part;
}				t_asm;

void				ft_parsing(t_asm *s);

#endif
