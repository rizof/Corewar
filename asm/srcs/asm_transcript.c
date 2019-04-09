/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_transcript.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:51:36 by amanuel           #+#    #+#             */
/*   Updated: 2019/04/09 18:39:44 by amanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"

void			ft_transcript_line(t_asm *s)
{
	s->i = 0;
	while (!s->error && s->i < *s->checksum[*(int8_t*)s->fresh])
	{
		if (s->i && (s->line[s->x] == SEPARATOR_CHAR))
			s->x += 1 + ft_count_whitespace(s->line + s->x + 1);
		else if (s->i)
			ft_error(s, s->y, s->x, NULL);
		ft_register_action(s);
	}
	if (!s->error
	&& ((*s->fresh == 1
		|| *s->fresh == 9
		|| *s->fresh == 12
		|| *s->fresh == 15)
	|| ft_strchr((char*)s->checksum[*(int8_t*)s->fresh], s->fresh[1])))
	{
		s->part = ft_lstaddnew_free(s->part, s->fresh, s->inst_len);
		s->current_position += s->inst_len;
	}
	else if (!s->error)
		ft_error(s, s->y, s->x, "instructions unauthorized");
}

void			ft_check_line(t_asm *s)
{
	s->i = 0;
	while (s->line[s->x + s->i] >= 97 && s->line[s->x + s->i] <= 122)
		s->i++;
	if (ft_strnstr(INSTRUCT_LST, s->line + s->x, s->i)
			&& (s->line[s->x + s->i] == SEPARATOR_CHAR
				|| s->line[s->x + s->i] == ' '
				|| s->line[s->x + s->i] == '\t'))
	{
		*s->fresh = (ft_strnstr(INSTRUCT_LST,
					s->line + s->x, s->i) - INSTRUCT_LST) / 6;
		s->x += s->i;
		s->x += ft_count_whitespace(s->line + s->x);
		s->inst_len = 1;
		if (!(*s->fresh == 1
		|| *s->fresh == 9
		|| *s->fresh == 12
		|| *s->fresh == 15))
			s->inst_len++;
		ft_transcript_line(s);
	}
	else
		ft_label_name_registration(s);
}

static void		ft_name_comment(t_asm *s, char *cmd, int len_max, char *type)
{
	if (!s->error && !(s->name_comment % 2) && ++s->name_comment)
	{
		s->j = ft_strlen(cmd);
		s->x = s->j + ft_count_whitespace(s->line + s->j) + 1;
		if (ft_strncmp(s->line, cmd, s->j) || s->line[s->x - 1] != '"')
			ft_error(s, s->y, 1, "Bad name/comment");
	}
	if (!s->error && ft_strchr(s->line + s->x, '"') && ++s->name_comment)
	{
		s->j = ft_strchr(s->line + s->x, '"') - (s->line + s->x);
		if ((s->i += s->j <= len_max
		|| (ft_printf("Champion %s too long (Max length %d)\n"
		, type, len_max) && !++s->error)))
			ft_strncpy(s->fresh, s->line + s->x, s->j);
		s->fresh = (char*)s->part->content + 4 + len_max + 8;
		s->x += s->j + 1;
		ft_check_endline(s);
	}
	else if (!s->error)
	{
		s->j = ft_strlen(s->line) - s->x;
		ft_strncpy(s->fresh, s->line + s->x, s->j);
		s->fresh += s->j;
		s->i += s->j;
	}
}

void			ft_transcript(t_asm *s)
{
	if (!s->error && !s->initialization && ++s->initialization)
	{
		s->part = (t_list*)ft_memalloc(sizeof(t_list));
		s->first_part = s->part;
		s->part->content_size = 4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH + 4;
		s->part->content = ft_memalloc(s->part->content_size);
		*(int*)s->part->content = ft_reverse_int(COREWAR_EXEC_MAGIC, 32);
		s->fresh = (char*)s->part->content + 4;
	}
	if (!s->error && s->name_comment <= 1)
		ft_name_comment(s, NAME_CMD_STRING, PROG_NAME_LENGTH, "name");
	else if (!s->error && s->name_comment <= 3)
		ft_name_comment(s, COMMENT_CMD_STRING, COMMENT_LENGTH, "comment");
	else if (!s->error)
	{
		s->x += ft_count_whitespace(s->line);
		if (s->line[s->x] && (s->fresh = (char*)ft_memalloc(11)))
			ft_check_line(s);
	}
}
