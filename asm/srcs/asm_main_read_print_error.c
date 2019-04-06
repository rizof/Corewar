/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main_read_print_error.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 02:26:05 by amanuel           #+#    #+#             */
/*   Updated: 2019/04/06 08:07:46 by amanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"

void			ft_check_endline(t_asm *s)
{
	if (!s->error)
	{
		s->x += ft_count_whitespace(s->line);
		if (!(s->line[s->x] == '\n'
		|| s->line[s->x] == COMMENT_CHAR
		|| !s->line[s->x]))
			ft_error(s, s->y, s->x, "Error end of line");
	}
}

char			ft_error(t_asm *s, int y, int x, char *str)
{
	s->y = y;
	s->x = x;
	if (str)
		ft_printf("%s\n", str);
	if (s->y)
		ft_printf("Lexical error at [%d:%d]\n", s->y, s->x);
	++s->error;
	return (0);
}

static char		ft_print_and_free(t_asm *s, char *av)
{
	int			ret;
	t_list		*byebye;

	ret = -1;
	s->part = s->first_part;
	if (!s->error && (ret++))
	{
		s->fresh = ft_strndup(av, s->file_name_size - 2);
		s->fresh = ft_strjoin_free(s->fresh, ".cor", 1, 0);
		ft_printf("Writing output program to %s\n", s->fresh);
		s->fd = open(s->fresh, O_RDWR | O_CREAT | O_TRUNC, 0644);
		free(s->fresh);
	}
	while (s->part)
	{
		if (!s->error)
			ft_putvoid_fd(s->part->content, s->part->content_size, s->fd);
		free(s->part->content);
		byebye = s->part;
		s->part = s->part->next;
		free(byebye);
	}
	ft_freetab((void**)s->checksum);
	free(s);
	return (ret);
}

static void		ft_checksum_initialization(t_asm *s)
{
	uint64_t	**wtf;

	s->checksum = (uint8_t**)ft_tabnew(17, 16, 8);
	wtf = (uint64_t**)s->checksum;
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

int				main(int ac, char **av)
{
	t_asm		*s;

	s = (t_asm*)ft_memalloc(sizeof(t_asm));
	ft_checksum_initialization(s);
	if (ac <= 1)
		ft_error(s, s->y, s->x, "Nombre d'arguments insuffisant");
	else if ((s->fd = open(*(++av), O_RDONLY)) > 2
	&& (lseek(s->fd, 0, SEEK_END) > 0)
	&& (s->file_name_size = ft_strlen(*av)) > 2
	&& !(ft_strcmp(".s", *av + s->file_name_size - 2)))
	{
		close(s->fd);
		s->fd = open(*av, O_RDONLY);
		while (!s->error && get_next_line(s->fd, &s->line) > 0
		&& ++s->y && !(s->x = 0))
			ft_transcript(s);
		*(int*)(s->first_part->content + 8 + PROG_NAME_LENGTH) =
						ft_reverse_int(s->current_position, 32);
		ft_put_labels_value(s);
		close(s->fd);
	}
	else
		ft_error(s, s->y, s->x, "Fichier invalide");
	return (ft_print_and_free(s, *av));
}
