/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:51:36 by amanuel           #+#    #+#             */
/*   Updated: 2018/12/31 07:12:41 by amanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"

static void		ft_print_and_free(t_asm *s, char *av)
{
	t_list		*byebye;

	if (!s->error)
	{
		s->file_name = ft_strndup(av, s->file_name_size - 2);
		s->file_name = ft_strjoin_free(s->file_name, ".cor", 1, 0);
		printf("Writing output program to %s\n", s->file_name);
		s->fd = open(s->file_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
		free(s->file_name);
	}
	s->binary_part = s->first_binary_part;
	while (s->binary_part)
	{
		if (!s->error)
			ft_putvoid_fd(s->binary_part->content,
					s->binary_part->content_size, s->fd);
		free(s->binary_part->content);
		byebye = s->binary_part;
		s->binary_part = s->binary_part->next;
		free(byebye);
	}
	free(s);
}

int			main(int ac, char **av)
{
	t_asm		*s;

	if (ac <= 1 && ft_printf("Nombre d'arguments insuffisant\n"))
		return (1);
	s = (t_asm*)ft_memalloc(sizeof(t_asm));
	if ((s->fd = open(*(++av), O_RDONLY)) > 2
		&& (lseek(s->fd, 0, SEEK_END) > 0)
		&& (s->file_name_size = ft_strlen(*av)) > 2
		&& !(ft_strcmp(".s", *av + s->file_name_size - 2)))
	{
		close(s->fd);
		s->fd = open(*av, O_RDONLY);
		while (!s->error && get_next_line(s->fd, &s->line) > 0)
			ft_parsing(s);
		close(s->fd);
	}
	else
		printf("Fichier invalide\n");
	ft_print_and_free(s, *av);
	return (0);
}
