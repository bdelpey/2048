/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:54:11 by ffourati          #+#    #+#             */
/*   Updated: 2014/05/17 04:48:56 by ffourati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifdef __linux
#  include <stdio.h>
# else
#  include <string.h>
# endif

# ifndef EOF
#  define EOF (-1)
# endif

# define KIBIO(len) ((len) << 0xA)
# define MEBIO(len) (KIBIO(KIBIO((len))))
# define LINE_READ_MAX (128)

typedef unsigned char	t_uchar;

typedef unsigned int	t_uint;

struct					s_line
{
	char				*raw;
	char				*head;
	char				*tail;
	char				*next;
	char				*line;
};

ssize_t					ft_putchar(char c);

ssize_t					ft_putstr(const char *s);

ssize_t					ft_putendl(const char *s);

ssize_t					ft_putnbr(int n);

size_t					ft_strlen(const char *s);

void					*ft_memset(void *b, int c, size_t len);

void					ft_bzero(void *s, size_t n);

void					*ft_memcpy(void *s1, const void *s2, size_t n);

void					*ft_memccpy(void *s1, const void *s2, int c, size_t n);

void					*ft_memchr(const void *s, int c, size_t n);
void					*ft_memrchr(const void *s, int c, size_t n);

int						ft_memcmp(const void *s1, const void *s2, size_t n);

void					*ft_memmove(void *s1, const void *s2, size_t n);

char					*ft_strcpy(char *s1, const char *s2);

char					*ft_strncpy(char *s1, const char *s2, size_t n);

char					*ft_strdup(const char *s1);

char					*ft_strcat(char *s1, const char *s2);

char					*ft_strncat(char *s1, const char *s2, size_t n);

size_t					ft_strlcat(char *dst, const char *src, size_t size);

char					*ft_strchr(const char *s, int c);

char					*ft_strrchr(const char *s, int c);

char					*ft_strstr(const char *s1, const char *s2);

char					*ft_strnstr(const char *s1, const char *s2, size_t n);

int						ft_strcmp(const char *s1, const char *s2);

int						ft_strncmp(const char *s1, const char *s2, size_t n);

int						ft_atoi(const char *str);

int						ft_isalpha(int c);

int						ft_isdigit(int c);

int						ft_isalnum(int c);

int						ft_isascii(int c);

int						ft_isprint(int c);

int						ft_toupper(int c);

int						ft_tolower(int c);

void					*ft_memalloc(size_t size);

void					ft_memdel(void **ap);

char					*ft_strnew(size_t size);

void					ft_strdel(char **as);

void					ft_strclr(char *s);

void					ft_striter(char *s, void (*f)(char *));

void					ft_striteri(char *s, void (*f)(unsigned int, char *));

char					*ft_strmap(char const *s, char (*f)(char));

char					*ft_strmapi(char const *s, char (*f)(unsigned int,
									char));

int						ft_strequ(char const *s1, char const *s2);

int						ft_strnequ(char const *s1, char const *s2, size_t n);

char					*ft_strsub(char const *s, unsigned int start,
									size_t len);

char					*ft_strjoin(char const *s1, char const *s2);

char					*ft_strtrim(char const *s);

char					**ft_strsplit(char const *s, char c);

char					*ft_itoa(int n);

size_t					ft_itoa_r(int n, char *buf);

ssize_t					ft_putchar_fd(char c, int fd);

ssize_t					ft_putstr_fd(char const *s, int fd);

ssize_t					ft_putendl_fd(char const *s, int fd);

ssize_t					ft_putnbr_fd(int n, int fd);

/*
**	Bonus
*/

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

t_list					*ft_lstnew(void const *content, size_t content_size);

void					ft_lstdel(t_list **als, void (*del)(void *, size_t));

void					ft_lstdelone(t_list **als, void (*del)(void *, size_t));

void					ft_lstdel(t_list **als, void (*del)(void *, size_t));

int						ft_lstadd(t_list **als, t_list *new);

int						ft_lstappend(t_list **als, t_list *new);

void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** Moar
*/

int						ft_isspace(int c);

size_t					ft_strlen_isxnot(char const *s, char fl,
											int (*pr)(int));

void					ft_strrev(char *s);

void					ft_memrev(void *seg, size_t len);

void					ft_lnkclear(void *el, size_t size);

void					ft_inssort_ints(int **av, int size);

void					ft_inssort_strings(char **av, size_t size);

char					*ft_strndup(char const *s, size_t len);

void					*ft_realloc(void *p, size_t old_size, size_t new_size);

char					*ft_strnjoin(int argc, ...);

ssize_t					ft_puts(const char *s);

ssize_t					ft_putnstr(int argc, ...);

ssize_t					ft_putnstr_fd(int fd, int argc, ...);

long int				ft_strtol(const char *nptr, char **endptr, int base);

ssize_t					ft_putlhex_fd(long int n, int fd);

ssize_t					ft_putlhex(long int n);

ssize_t					ft_fmtputlhex_fd(long int n, int fd, int format);

ssize_t					ft_fmtputlhex(long int n, int format);

ssize_t					ft_putlong(long int n);

ssize_t					ft_putlong_fd(long int n, int fd);

ssize_t					ft_tee_s(int fd_in, int fd_out[], int nfds);

/*
** Dual-linked list functions
*/

typedef struct			s_dlist
{
	void				*content;
	size_t				content_size;
	struct s_dlist		*next;
	struct s_dlist		*prev;
}						t_dlist;

t_dlist					*ft_dlstnew(void const *content, size_t content_size);

void					ft_dlstadd(t_dlist **adlst, t_dlist *new);

void					ft_dlstins(t_dlist **pr_dlst, t_dlist *lnk,
									t_dlist **nx);

void					ft_dlstdelone(t_dlist **adlst,
										void (*del)(void *, size_t));

void					ft_dlstdel(t_dlist **adlst,
									void (*del)(void *, size_t));

#endif
