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

static void		ft_binary_instruction(t_asm *s)
{
	// en cours de travaillage
	s->p = (char*)s->binary_part->content +
			4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH + 4;
	*s->p = 'W';
}

static void		ft_binary_comment(t_asm *s)
{
	s->x = 0;
	if (!s->binary_comment && ++s->binary_comment && (s->x = 10))
		if (ft_strncmp(s->line, COMMENT_CMD_STRING,
					ft_strlen(COMMENT_CMD_STRING)) && ++s->error)
			printf("Lexical error at [2:1]\n");
	if (!s->error && ft_strchr(s->line + s->x, '"'))
	{
		s->n = ft_strchr(s->line + s->x, '"') - (s->line + s->x);
		if ((s->i += s->n <= COMMENT_LENGTH
		|| (ft_printf("Champion comment too long (Max length %d)\n"
		, COMMENT_LENGTH) && s->error++)))
			ft_strncpy(s->p, s->line + s->x, s->n);
		++s->binary_comment;
	}
	else if (!s->error)
	{
		s->n = ft_strlen(s->line) - s->x;
		ft_strncpy(s->p, s->line + s->x, s->n);
		s->p += s->n;	
	}
}

static void		ft_binary_name(t_asm *s)
{
	s->x = 0;
	if (!s->binary_name && ++s->binary_name && (s->x = 8))
		if (ft_strncmp(s->line, NAME_CMD_STRING,
					ft_strlen(NAME_CMD_STRING)) && ++s->error)
			printf("Lexical error at [1:1]\n");
	if (!s->error && ft_strchr(s->line + s->x, '"'))
	{
		s->n = ft_strchr(s->line + s->x, '"') - (s->line + s->x);
		if ((s->i += s->n <= PROG_NAME_LENGTH
		|| (ft_printf("Champion name too long (Max length %d)\n"
		, PROG_NAME_LENGTH) && s->error++)))
			ft_strncpy(s->p, s->line + s->x, s->n);
		s->p = (char*)s->binary_part->content + 4 + PROG_NAME_LENGTH + 8;
		++s->binary_name;
	}
	else if (!s->error)
	{
		s->n = ft_strlen(s->line) - s->x;
		ft_strncpy(s->p, s->line + s->x, s->n);
		s->p += s->n;	
	}
}

static void		ft_binary_init(t_asm *s)
{
	s->binary_part = (t_list*)ft_memalloc(sizeof(s->binary_part));
	s->first_binary_part = s->binary_part;
	s->binary_part->content_size = 4 + PROG_NAME_LENGTH + 8 + COMMENT_LENGTH + 4 +(50);
	s->binary_part->content = ft_memalloc(s->binary_part->content_size);
	*(int*)s->binary_part->content = ft_reverse_int(COREWAR_EXEC_MAGIC);
	s->p = (char*)s->binary_part->content + 4;
}

void		ft_parsing(t_asm *s)
{
	if (!s->binary_init && ++s->binary_init)
		ft_binary_init(s);
	if (s->binary_name <= 1)
		ft_binary_name(s);
	else if (s->binary_comment <= 1)
		ft_binary_comment(s);
	else
		ft_binary_instruction(s);
//	printf("%s\n", s->line);
}
