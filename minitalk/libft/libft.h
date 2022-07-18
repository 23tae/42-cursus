/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 00:23:34 by taehooki          #+#    #+#             */
/*   Updated: 2022/07/17 09:30:23 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

# define COLOR_RED		"\x1b[31m"
# define COLOR_GREEN	"\x1b[32m"
# define COLOR_BLUE		"\x1b[34m"
# define COLOR_YELLOW	"\x1b[33m"
# define COLOR_WHITE	"\x1b[37m"
# define COLOR_RESET	"\x1b[0m"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// String
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strcjoin(char *str, char c);

// Memory
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_calloc(size_t count, size_t size);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

// Etc
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_itoa(int n);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_atoi(const char *str);
int			ft_toupper(int c);
int			ft_tolower(int c);
void		ft_putstr_color_fd(char *color, char *s, int fd);

// List
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
int			ft_lstsize(t_list *lst);

// ft_printf
int			ft_print_str(char *str);
int			ft_print_char(char c);
int			ft_print_dec(int n);
int			ft_print_dec_unsigned(unsigned int n);
int			ft_print_hex(unsigned int n, char c);
int			ft_print_ptr(void *addr);
int			ft_printf(const char *format, ...);

// Math
int			ft_abs(int n);
int			ft_pow(int base, int exp);
int			ft_digitnum(int n);
int			ft_isspace(char c);
int			ft_isoverflow(long long n);
#endif
