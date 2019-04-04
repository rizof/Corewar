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

char			ft_error(t_asm *s, int y, int x, char *str)
{
	printf("%s\n", str);
	printf("%s[%c]\n", s->line, s->line[s->x]);
	s->y = y;
	s->x = x;
	printf("Lexical error at [%d:%d]\n", s->y, s->x);
	++s->error;
	return (0);
}

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
	s->part = s->first_part;
	while (s->part)
	{
		if (!s->error)
			ft_putvoid_fd(s->part->content,
					s->part->content_size, s->fd);
		free(s->part->content);
		byebye = s->part;
		s->part = s->part->next;
		free(byebye);
	}
	free(s->inst_tab);
	free(s);
}

static void		init_inst_tab(t_asm *s)
{
	uint64_t 	**wtf;

	s->inst_tab = (uint8_t**)ft_tabnew(17, 16, 8);
	wtf = (uint64_t**)s->inst_tab;
	wtf[1][0] = 32769;
	wtf[2][0] = 9490434;
	wtf[3][0] = 5271554;
	wtf[4][0] = 21507;
	wtf[5][0] = 21507;
	wtf[6][0] = 8400520301525660675;
	wtf[6][1] = 21604;
	wtf[7][0] = 8400520301525660675;
	wtf[7][1] = 21604;
	wtf[8][0] = 8400520301525660675;
	wtf[8][1] = 21604;
	wtf[9][0] = 32769;
	wtf[10][0] = 23754487627047939;
	wtf[11][0] = 23741086316132355;
	wtf[12][0] = 32769;
	wtf[13][0] = 9490434;
	wtf[14][0] = 23754487627047939;
	wtf[15][0] = 32769;
	wtf[16][0] = 16385;
}

int			main(int ac, char **av)
{
	t_asm		*s;

	if (ac <= 1 && ft_printf("Nombre d'arguments insuffisant\n"))
		return (1);
	s = (t_asm*)ft_memalloc(sizeof(t_asm));
	init_inst_tab(s);
	if ((s->fd = open(*(++av), O_RDONLY)) > 2
		&& (lseek(s->fd, 0, SEEK_END) > 0)
		&& (s->file_name_size = ft_strlen(*av)) > 2
		&& !(ft_strcmp(".s", *av + s->file_name_size - 2)))
	{
		close(s->fd);
		s->fd = open(*av, O_RDONLY);
		while (!s->error && get_next_line(s->fd, &s->line) > 0
				&& ++s->y && !(s->x = 0))
			ft_parse_and_transcript(s);
		ft_exec_labels(s);
		close(s->fd);
	}
	else if (++s->error)
		printf("Fichier invalide\n");
	ft_print_and_free(s, *av);
	return (0);
}
