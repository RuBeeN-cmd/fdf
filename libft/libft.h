/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrollin <rrollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:05:26 by rrollin           #+#    #+#             */
/*   Updated: 2022/05/16 14:28:22 by rrollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1024

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char		*ft_itoa(int n);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_lstsize(t_list *lst);
size_t		ft_strlen(const char *s);
t_list		*ft_lstlast(t_list *lst);
int			ft_atoi(const char *nptr);
char		*ft_strdup(const char *s);
t_list		*ft_lstnew(void *content);
void		ft_putnbr_fd(int n, int fd);
void		ft_bzero(void *s, size_t n);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		**ft_split(char const *s, char c);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		*ft_memchr(const void *s, int c, size_t n);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstiter(t_list *lst, void (*f)(void *));
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strnstr(const char *big, const char *little, size_t len);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int			ft_str_add_char(char **str, char c);
char		*ft_read_file(int fd);
int			ft_atoi_base(char *str, char *base);
size_t		ft_tablen(const void **tab);
void		**ft_tabadd_row(void **tab);

// Get next line
typedef struct s_dict_cell
{
	int					fd;
	int					ret;
	char				*buf;
	struct s_dict_cell	*next;
}	t_dict_cell;

char		*get_next_line(int fd);
t_dict_cell	*ft_lstget_cell(int fd, t_dict_cell **list);
t_dict_cell	*ft_new_fd(int fd);
void		ft_del_fd(t_dict_cell *cell, t_dict_cell **list);
int			ft_chr(char *str, char c);
int			ft_loop_read(int fd, t_dict_cell *cell);
char		*ft_join_free(char *s1, char *s2);
char		*ft_sub(char *s, int start, int len);
int			ft_read(char *str, t_dict_cell *cell, int fd);
char		*ft_start_read(int fd, t_dict_cell **list, t_dict_cell **tp);
//---

#endif
