/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:35:24 by amanuel           #+#    #+#             */
/*   Updated: 2018/07/29 03:25:14 by amanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct		s_id
{
	char			*p;
	short			plen;
	short			ins;
	va_list			vlst;
	char			hash;
	char			zero;
	char			minu;
	char			plus;
	char			spac;
	short			prec;
	short			widt;
	char			arg;
}					t_id;

int					ft_printf(char *s, ...);
void				ft_arg_di(t_id *id);
void				ft_arg_uox(t_id *id, char c);
void				ft_arg_s(t_id *id);
void				ft_arg_c(t_id *id);
void				ft_exe_flags(t_id *id, char **buff);

int					ft_atoi(char *str);
char				*ft_itoa(int n);
char				*ft_ltoa(long i);
char				*ft_uitoa_base(unsigned int n, char base);
char				*ft_ultoa_base(uintmax_t n, char base);
char				*ft_itostr(int *n, int m);
char				*ft_strset(char *b, char c, short len);
int					ft_printf(char *s, ...);
char				*ft_lilstr(char a, char b, char c);
char				*ft_strdup(char *s);
char				*ft_strndup(char *s, short i);
char				*ft_strins_free(char *s1, char *s2, short i, char f);
char				*ft_strjoin_free(char *s1, char *s2, char f1, char f2);
char				*ft_strnjoin_free(char *s1, char *s2, short i, char f);
short				ft_strlen(char *s);
char				*ft_strnew(short size);

#endif
