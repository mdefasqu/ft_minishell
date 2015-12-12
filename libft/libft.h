/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdefasqu <mdefasqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:50:08 by mdefasqu          #+#    #+#             */
/*   Updated: 2015/10/29 12:35:02 by mdefasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 10

# include <string.h>

typedef struct			s_box
{
	int					ret;
	char				*tmp;
	int					fd;
}						t_box;

typedef struct			s_list_libft
{
	void				*content;
	size_t				content_size;
	struct s_list_libft	*next;
}						t_list_libft;

int						ft_atoi(const char *str);
void					ft_bzero(void *s, size_t n);
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isprint(int c);
char					*ft_itoa(int n);
void					*ft_memalloc(size_t size);
void					*ft_memccpy(void *dst, const void *src,
							int c, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memcpy(void	*dst, const	void *src, size_t n);
void					ft_memdel(void **ap);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memset(void *b, int c, size_t len);
void					ft_putchar(char c);
void					ft_putchar_fd(char c, int fd);
void					ft_putendl(char const *s);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr(int n);
void					ft_putnbr_fd(int n, int fd);
void					ft_putstr(char const *s);
void					ft_putstr_fd(char const *s, int fd);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strchr(const char *s, int c);
void					ft_strclr(char *s);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strcpy(char *dst, const char *src);
void					ft_strdel(char **as);
char					*ft_strdup(const char *s1);
int						ft_strequ(char const *s1, char const *s2);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strjoin(char const *s1, char const *s2);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
size_t					ft_strlen(const char *s);
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
							char (*f)(unsigned int, char));
char					*ft_strncat(char *s1, const char *s2, size_t n);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strncpy(char *dst, const char *src, size_t n);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strnew(size_t size);
char					*ft_strnstr(const char *s1, const char *s2, size_t n);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *s1, const char *s2);
char					*ft_strsub(char const *s, unsigned int start,
							size_t len);
char					*ft_strtrim(char const *s);
int						ft_tolower(int c);
int						ft_toupper(int c);
char					**ft_strsplit(char const *s, char c);
int						get_next_line(int const fd, char **line);
void					ft_print_tabi(int **tabi, int nb_line, int nb_case);
void					ft_print_tabc(char **tabc);
int						ft_isblanck(int c);
t_list_libft			*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdel(t_list_libft **atsl,
							void (*del)(void*, size_t));
void					ft_lstdelone(t_list_libft **atsl,
							void (*del)(void *, size_t));
void					ft_lstadd(t_list_libft **alts, t_list_libft *news);
void					ft_lstiter(t_list_libft *lst,
							void(*f)(t_list_libft *elem));
t_list_libft			*ft_lstmap(t_list_libft *lst,
							t_list_libft *(*f)(t_list_libft*));
void					ft_bubble_sort_char(char **tabc, int nb_element);
void					ft_bubble_sort_char_reverse(char **tabc,
							int nb_element);
void					ft_bubble_sort_int(int *tabi, int nb_element);
void					ft_bubble_sort_int_reverse(int *tabi, int nb_element);
void					ft_mini_tabi(int *tab, int nb_element);
char					*ft_strjoin_path(char *s1, char *s2);
void					ft_print_tabc_debug(char **tabc);
char					*ft_strcut(const char *str, int start, int end);
size_t					ft_strtab_len(char **source);
char					get_file_type(char *path);
int						ft_strstr_pos(const char *s1, const char *s2);
char					*ft_str_replace_in_str(const char *find,
							const char *replace, const char *str);
void					ft_strdel_2d(char ***tab);
void					ft_strdel_3d(char ****tab);

#endif
