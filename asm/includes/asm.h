/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */

/*   By: amanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 20:51:26 by amanuel           #+#    #+#             */
/*   Updated: 2018/12/31 03:51:17 by amanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../libft/includes/libft.h"

# define INSTRUCT_LST		"______live__ld____st____add___sub___and___or____xor___zjmp__ldi___sti___fork__lld___lldi__lfork_aff___"  

/*
# define INSTRUCT_TAB		{LIVE,LD,ST,ADD,SUB,AND,OR,XOR,ZJMP,LDI,STI,FORK,LLD,LLDI,LFORK,AFF}
# define LIVE			(uint8_t[2]){1,128}
# define LD			(uint8_t[3]){2,208,144}
# define ST			(uint8_t[3]){2,112,80}
# define ADD			(uint8_t[2]){3,84}
# define SUB			(uint8_t[2]){3,84}
# define AND			(uint8_t[10]){3,244,228,212,180,164,148,116,100,84}
# define OR			(uint8_t[10]){3,244,228,212,180,164,148,116,100,84}
# define XOR			(uint8_t[10]){3,244,228,212,180,164,148,116,100,84}
# define ZJMP			(uint8_t[2]){1,128}
# define LDI			(uint8_t[7]){3,228,212,164,148,100,84}
# define STI			(uint8_t[7]){3,120,116,104,100,88,84}
# define FORK			(uint8_t[2]){1,128}
# define LLD			(uint8_t[3]){2,208,144}
# define LLDI			(uint8_t[7]){3,228,212,164,148,100,84}
# define LFORK			(uint8_t[2]){1,128}
# define AFF			(uint8_t[2]){1,64}
*/

typedef struct			s_asm
{


	int			fd;
	char			*line;
	char			*file_name;
	int			file_name_size;

	struct s_list		*first_part;
	struct s_list		*part;
	char			*p;
	int			current_position;
	char			malloc_and_magicnb;
	char			name_and_comment;
	uint8_t			**inst_tab;
	int			inst_val;
	int			inst_len;
	char			*label_name;
	char			**label_name_lst;
	char			**label_called_lst;
	int			*label_val;
	int			**label_val_lst;
	int			**label_called_val_lst;
	void			*label_pointer;
	void			**label_pointer_lst;

	int			i;
	int			j;

	char			error;
	int			y;
	int			x;

	int			len;
}				t_asm;

void				ft_parse_and_transcript(t_asm *s);
void				ft_instruction_line(t_asm *s);
char				ft_error(t_asm *s, int y, int x, char *str);
void				ft_exec_labels(t_asm *s);

#endif
