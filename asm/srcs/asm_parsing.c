/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:51:36 by amanuel           #+#    #+#             */
/*   Updated: 2018/12/31 07:12:41 by amanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"

static void		ft_label(t_asm *s)
{
	(void)s;
}

static void		ft_register_action(t_asm *s)
{	
	if (!s->error && s->line[s->x] == 'r' && ++s->x)
	{
		s->inst_val = ft_atoi(s->line + s->x);
		s->p[s->inst_len] = s->inst_val;
		s->x += ft_isint(s->line + s->x, 8);
		s->p[1] += ft_pow(2, 8 - (2 * ++s->i));
		s->inst_len += 1;
	}
	else if (!s->error && s->line[s->x] == LABEL_CHAR && ++s->x)
	{

		s->p[1] += ft_pow(2, 8 - ((2 * ++s->i) - 1)) + ft_pow(2, 8 - (2 * s->i));
	}
	else if (!s->error && s->line[s->x] == DIRECT_CHAR && ++s->x)
	{
		s->inst_val = ft_atoi(s->line + s->x);
		*(int*)(s->p + s->inst_len) = ft_reverse_int(s->inst_val);
		s->x += ft_isint(s->line + s->x, 8);
		s->p[1] += ft_pow(2, 8 - ((2 * ++s->i) - 1));
		s->inst_len += 4;
	}
	else
		ft_error(s, s->y, s->x);
}

static void		ft_instruction_line(t_asm *s)
{
	s->i = 0;
	while (s->line[s->x + s->i] >= 97 && s->line[s->x + s->i] <= 122)
		s->i++;
	if (ft_strnstr(INSTRUCT_LST, s->line + s->x, s->i))
		*s->p = (ft_strnstr(INSTRUCT_LST, s->line + s->x, s->i) - INSTRUCT_LST) / 6;
	else
	{
		ft_label(s);
		return ;
	}
	s->x += s->i;
	s->inst_len = 2;
	s->i = 0;
	while (!s->error && s->i < *s->inst_tab[*(int8_t*)s->p])
	{
		s->x += ft_count_whitespace(s->line + s->x);
		if (s->i && (s->line[s->x] == SEPARATOR_CHAR || !s->error++))
			s->x += 1 + ft_count_whitespace(s->line + s->x + 1);
		ft_register_action(s);
	}
	if (!s->error && ft_strchr((char*)s->inst_tab[*(int8_t*)s->p], s->p[1]))
		s->part = ft_lstaddnew_free(s->part, s->p, s->inst_len);
	else
		ft_error(s, s->y, s->x);
}

static void		ft_name_and_comment(t_asm *s, char *cmd, int maxbits, char *type)
{
	int		len;

	if (!(s->name_and_comment % 2) && ++s->name_and_comment)
	{
		len = ft_strlen(cmd);
		s->x = len + ft_count_whitespace(s->line + len) + 1;
		if (ft_strncmp(s->line, cmd, len) || s->line[s->x - 1] != '"')
			ft_error(s, s->y, 1);
	}
	if (!s->error && ft_strchr(s->line + s->x, '"'))
	{
		s->j = ft_strchr(s->line + s->x, '"') - (s->line + s->x);
		if ((s->i += s->j <= maxbits
		|| (ft_printf("Champion %s too long (Max length %d)\n"
		, type, maxbits) && !++s->error)))
			ft_strncpy(s->p, s->line + s->x, s->j);
		s->p = (char*)s->part->content + 4 + maxbits + 8;
		++s->name_and_comment;
	}
	else if (!s->error)
	{
		s->j = ft_strlen(s->line) - s->x;
		ft_strncpy(s->p, s->line + s->x, s->j);
		s->p += s->j;	
	}
}

void		ft_parse_and_transcript(t_asm *s)
{
	if (!s->malloc_and_magicnb && ++s->malloc_and_magicnb)
	{
		s->part = (t_list*)ft_memalloc(sizeof(t_list));
		s->first_part = s->part;
		s->part->content_size = 4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH + 4;
		s->part->content = ft_memalloc(s->part->content_size);
		*(int*)s->part->content = ft_reverse_int(COREWAR_EXEC_MAGIC);
		s->p = (char*)s->part->content + 4;
	}
	if (!s->error && s->name_and_comment <= 1)
		ft_name_and_comment(s, NAME_CMD_STRING, PROG_NAME_LENGTH, "name");
	else if (!s->error && s->name_and_comment <= 3)
		ft_name_and_comment(s, COMMENT_CMD_STRING, COMMENT_LENGTH, "comment");
	else if (!s->error)
	{
		s->x = ft_count_whitespace(s->line);
		s->p = (char*)ft_memalloc(11);
		if (s->line[s->x])
			ft_instruction_line(s);
	}
}
