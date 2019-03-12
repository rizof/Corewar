/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 06:17:16 by tmanuel           #+#    #+#             */
/*   Updated: 2018/12/27 15:20:55 by amanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int				ft_atoi(char *str);
long			ft_atol(char *str);
char			*ft_itoa(int i);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			*ft_memset(void *b, int c, size_t len);
short			ft_pow(short nb, unsigned short pow);
char			*ft_strchr(char *str, int c);
void			ft_strclr(char *s);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(char *str);
char			*ft_strndup(char *str, short i);
char			*ft_strjoin_free(char *s1, char *s2, char f1, char f2);
size_t			ft_strlen(char *str);
void			ft_strndel(char **data, size_t len);
char			*ft_strndup(char *src, short n);
char			*ft_strnew(short size);
char			*ft_strnjoin_free(char *s1, char *s2, short i, char f);
void			**ft_tabnew(int y, int x, char type);
int				get_next_line(int fd, char **line);
int				ft_findc(char *str, char c);
int				ft_printf(char *s, ...);
char			*ft_ltoa(long i);
char			*ft_uitoa_base(unsigned int n, char base);
char			*ft_ultoa_base(uintmax_t n, char base);
char			*ft_itostr(int *n, int m);
char			*ft_strset(char *b, char c, short len);
char			*ft_lilstr(char a, char b, char c);
char			*ft_strins_free(char *s1, char *s2, short i, char f);
void			ft_freetab(void ***tab);
void			**ft_addarray(void ***tab, void **str);
int				ft_tablen(void **tab);
int				ft_strcmp(char *s1, char *s2);
int				ft_strncmp(char *s1, char *s2, int n);
int				ft_isint(char *line, char bits);
void				ft_puttab(char **tab);

#endif
