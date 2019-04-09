/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:51:36 by amanuel           #+#    #+#             */
/*   Updated: 2019/04/09 19:36:39 by amanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"

void			ft_put_labels_value(t_asm *s)
{
	s->i = 0 + (-1);
	while (!s->error && s->label_called_lst && s->label_called_lst[++s->i])
	{
		s->j = -1;
		if ((s->j = ft_strtab(s->label_name_lst, s->label_called_lst[s->i])) >= 0)
		{
			if (s->label_called_val_lst[s->i][1] == 16)
				*(short*)(s->label_pointer_lst[s->i]) = ft_reverse_int(
		*s->label_val_lst[s->j] - *s->label_called_val_lst[s->i], 16);
			else
				*(int*)(s->label_pointer_lst[s->i]) = ft_reverse_int(
		*s->label_val_lst[s->j] - *s->label_called_val_lst[s->i], 32);
		}
		else
			ft_error(s, s->label_called_val_lst[s->i][2],
					s->label_called_val_lst[s->i][3], "exec labels");
	}
}

void			ft_label_value_registration(t_asm *s, char bits)
{
	s->j = 0;
	while (s->line[s->x + s->j] && ft_strchr(LABEL_CHARS, s->line[s->x + s->j]))
		s->j++;
	if (s->j)
	{
		s->label_name = ft_strndup(s->line + s->x, s->j);
		s->label_called_lst = (char**)ft_addarray(
			(void**)s->label_called_lst, (void*)s->label_name);
		s->label_val = (int*)ft_memalloc(sizeof(int) * 4);
		s->label_val[0] = s->current_position;
		s->label_val[1] = bits;
		s->label_val[2] = s->y;
		s->label_val[3] = s->x;
		s->label_called_val_lst = (int**)ft_addarray(
			(void**)s->label_called_val_lst, (void*)s->label_val);
		s->label_pointer_lst = ft_addarray(
			s->label_pointer_lst, s->fresh + s->inst_len);
		s->x += s->j;
		s->x += ft_count_whitespace(s->line + s->x);
		s->inst_len += 2;
		if (bits == 32)
			s->inst_len += 2;
	}
	else
		ft_error(s, s->y, s->x, "label value registration");
}

char			ft_label_name_registration(t_asm *s)
{
	s->i = 0;
	while (ft_strchr(LABEL_CHARS, s->line[s->x + s->i]))
		s->i++;
	if (s->line[s->x + s->i] == LABEL_CHAR)
	{
		s->label_name = ft_strndup(s->line + s->x, s->i);
		s->label_name_lst = (char**)ft_addarray(
			(void**)s->label_name_lst, (void*)s->label_name);
		s->label_val = (int*)ft_memalloc(sizeof(int));
		*s->label_val = s->current_position;
		s->label_val_lst = (int**)ft_addarray(
			(void**)s->label_val_lst, (void*)s->label_val);
		s->x += s->i + 1;
		s->x += ft_count_whitespace(s->line + s->x);
		ft_check_line(s);
	}
	else if (s->line[s->x + s->i] == COMMENT_CHAR)
		free(s->fresh);
	else
		ft_error(s, s->y, s->x, "label name registration");
	return (1);
}

void			ft_register_action_direct(t_asm *s)
{
	if (!s->error && s->line[s->x] == DIRECT_CHAR && ++s->x)
	{
		s->sum += ft_pow(2, 8 - ((2 * ++s->i) - 1));
		s->fresh[1] += ft_pow(2, 8 - ((2 * s->i) - 1));
		if (s->line[s->x] == LABEL_CHAR && ft_strchr(DIRLAB_SHORT, *s->fresh) && ++s->x)
			ft_label_value_registration(s, 32);
		else if (s->line[s->x] == LABEL_CHAR && ++s->x)
			ft_label_value_registration(s, 16);
		else
		{
			s->inst_val = ft_atoi(s->line + s->x);
			if (ft_strchr(DIR_SHORT, *s->fresh) && (s->inst_len += 2))
				*(short*)(s->fresh + s->inst_len - 2) = ft_reverse_int(s->inst_val, 16);
			else if ((s->inst_len += 4))
				*(int*)(s->fresh + s->inst_len - 4) = ft_reverse_int(s->inst_val, 32);
			s->x += ft_isint(s->line + s->x, 32);
		}
	}
	else if (!s->error)
		ft_error(s, s->y, s->x, "invalid action");
}

void			ft_register_action(t_asm *s)
{
	if (!s->error && s->line[s->x] == 'r' && ++s->x)
	{
		s->inst_val = ft_atoi(s->line + s->x);
		s->fresh[s->inst_len] = s->inst_val;
		s->x += ft_isint(s->line + s->x, 8);
		s->sum += ft_pow(2, 8 - (2 * ++s->i));
		s->fresh[1] += ft_pow(2, 8 - (2 * s->i));
		s->inst_len += 1;
	}
	else if (!s->error && s->line[s->x] == LABEL_CHAR && ++s->x)
	{
		ft_label_value_registration(s, 16);
		s->sum += ft_pow(2, 8 - ((2 * ++s->i) - 1)) + ft_pow(2, 8 - (2 * s->i));
		s->fresh[1] += ft_pow(2, 8 - ((2 * s->i) - 1)) + ft_pow(2, 8 - (2 * s->i));
	}
	else
		ft_register_action_direct(s);
}
