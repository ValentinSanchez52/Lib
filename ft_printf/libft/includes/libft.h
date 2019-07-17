/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanchez <vsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:53:41 by vsanchez          #+#    #+#             */
/*   Updated: 2019/06/06 23:14:18 by vsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>

# define BUFF_SIZE 4096
# define PRINT_ERROR_ALLOWED 0
# define NRM		"\e[0m"
# define BLACK		"\e[30m"
# define RED		"\e[31m"
# define GREEN		"\e[32m"
# define YELLOW		"\e[33m"
# define BLUE		"\e[34m"
# define PURPLE		"\e[35m"
# define CYAN		"\e[36m"
# define WHITE		"\e[37m"

/*
**	STRUCTURES
*/

/*
**	Capacity is the allocated number of bytes
**	Str_len is the current len of the string stored in string
*/
typedef struct	s_str
{
	uint64_t	capacity;
	uint64_t	str_len;
	char		*str;
}				t_str;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
**	FUNCTIONS
**
**	Memory
*/

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
char			*ft_realloc(char *buff, size_t size, size_t n);
void			ft_memdel(void **ap);

/*
**	Read functions
*/

char			*ft_get_file_content(char *filename);
char			*ft_get_stdin_content(void);
void			ft_get_fd_content(t_str *string, int fd);
char			**ft_get_arg_str_tab(char **arguments, size_t arg_nb);
char			*ft_get_arg_in_1_str(char **arguments, size_t arg_nb);

/*
**	Parsing functions
**	(ft_str_to_tab & free_str_tab in ft_str_to_tab.c)
*/

char			**ft_str_to_tab(const char *str);
void			free_str_tab(char **tab);
int				nb_words(const char *s, char c);

/*
**	Strings
*/

void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strrev(char *str);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_str_to_upper_case(char *str);
int				ft_str_is_alpha(const char *str);
int				ft_str_is_lowercase(const char *str);
int				ft_str_is_numeric(const char *str);
int				ft_str_is_printable(const char *str);
int				ft_str_is_uppercase(const char *str);
char			*ft_strskip(char *s, int (*cmp)(int));

/*
**	Numbers
*/

char			*ft_itoa(int n);
int				ft_atoi(const char *str);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
unsigned long	ft_absolute_int(int n);
void			ft_intswap(int *a, int *b);
int				ft_nb_len(unsigned int nb, unsigned int base);
int				ft_int_min(int nb1, int nb2);
int				ft_int_max(int nb1, int nb2);

/*
**	Chars
*/

void			ft_putchar_fd(char c, int fd);
int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_islower(int c);
int				ft_isblank(int c);
int				ft_iscntrl(int c);
int				ft_isgraph(int c);
int				ft_isxdigit(int c);
void			ft_putchar(char c);
void			ft_putchar_nl(char c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isnumchar(int c);
int				ft_issign(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
**	Debug
**	(ft_print_str_tab is in ft_str_to_tab.c)
*/

void			ft_putaddr(void const *p);
void			ft_print_error(char *error_name);
void			ft_print_str_tab(char **tab);

/*
**	Basic Lists
*/

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstputstr(t_list *alst);
void			ft_lstappend(t_list **alst, t_list *new);

#endif
