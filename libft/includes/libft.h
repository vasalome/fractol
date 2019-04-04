/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 14:32:35 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 14:22:41 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*ft_itoa(int n);
char				*ft_strdup(const char *src);
char				*ft_strnew(size_t size);
char				*ft_strrev(char *str);
char				*ft_strcpy(char *dest, const char *src);
size_t				ft_strlen(const char *str);
int					ft_pow(int nb, int power);
char				*ft_dtoa(double nb, unsigned int precision);

#endif
