/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 00:41:00 by amanuel           #+#    #+#             */
/*   Updated: 2019/04/06 07:37:00 by amanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../libft/includes/libft.h"

# define INSTRUCT_LST		"______live__ld____st____add___sub___and___or____xor___zjmp__ldi___sti___fork__lld___lldi__lfork_aff___"

/* # define CHECKSUM	{LIVE,LD,ST,ADD,SUB,AND,OR,XOR,ZJMP,LDI,STI,FORK,LLD,LLDI,LFORK,AFF}
# define LIVE			(uint8_t[2]){1,128}
# define LD				(uint8_t[3]){2,208,144}
# define ST				(uint8_t[3]){2,112,80}
# define ADD			(uint8_t[2]){3,84}
# define SUB			(uint8_t[2]){3,84}
# define AND			(uint8_t[10]){3,244,228,212,180,164,148,116,100,84}
# define OR				(uint8_t[10]){3,244,228,212,180,164,148,116,100,84}
# define XOR			(uint8_t[10]){3,244,228,212,180,164,148,116,100,84}
# define ZJMP			(uint8_t[2]){1,128}
# define LDI			(uint8_t[7]){3,228,212,164,148,100,84}
# define STI			(uint8_t[7]){3,120,116,104,100,88,84}
# define FORK			(uint8_t[2]){1,128}
# define LLD			(uint8_t[3]){2,208,144}
# define LLDI			(uint8_t[7]){3,228,212,164,148,100,84}
# define LFORK			(uint8_t[2]){1,128}
# define AFF			(uint8_t[2]){1,64}*/

typedef struct			s_asm
{

	int					fd;
	char				*line;
	int					file_name_size;
	uint8_t				**checksum;
	uint8_t				sum;
	struct s_list		*first_part;
	struct s_list		*part;
	char				initialization;
	char				name_comment;

	int					current_position;
	int					inst_val;
	int					inst_len;
	char				*label_name;
	char				**label_name_lst;
	char				**label_called_lst;
	int					*label_val;
	int					**label_val_lst;
	int					**label_called_val_lst;
	void				*label_pointer;
	void				**label_pointer_lst;

	char				*fresh;
	int					i;
	int					j;

	char				error;
	int					y;
	int					x;
}						t_asm;

void					ft_transcript(t_asm *s);
void					ft_transcript_line(t_asm *s);
void					ft_check_line(t_asm *s);
void					ft_label_value_registration(t_asm *s, char bits);
char					ft_label_name_registration(t_asm *s);
void					ft_put_labels_value(t_asm *s);
void					ft_register_action(t_asm *s);
void					ft_check_endline(t_asm *s);
char					ft_error(t_asm *s, int y, int x, char *str);

#endif
