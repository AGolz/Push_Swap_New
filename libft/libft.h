/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:10:58 by emaksimo          #+#    #+#             */
/*   Updated: 2023/07/18 18:56:16 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

int		ft_atoi(const char *str);
int		ft_free_array(char **array, int ret_val);
int		ft_abs(int nb);
int		ft_isalnum(int ch);
int		ft_isalpha(int ch);
int		ft_isascii(int ch);
int		ft_isdigit(int ch);
int		ft_isprint(int ch);
int		ft_memcmp(const void *arr_1, const void *arr_2, size_t n);
int		ft_strcmp(const char *str_1, const char *str_2);
int		ft_strncmp(const char *str_1, const char *str_2, size_t n);
int		ft_tolower(int ch);
int		ft_toupper(int ch);
int		ft_putchar_fd(char c, int fd);
int		ft_putnchar_fd(char c, int fd, int n);
int		ft_putstrn_fd(char *s, int fd, int n);
int		ft_nbrlen(unsigned long nbr, unsigned long base);
int		ft_putendl_fd(char *s, int fd);
int		ft_putstr_fd(char *s, int fd);

char	*ft_strchr(const char *str, int ch);
char	*ft_strdup(const char *str);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *str, int ch);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	**ft_strsplit(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strncpy(char *dst, const char *src, size_t len);

void	ft_bzero(void *buf, size_t count);
void	*ft_calloc(size_t number, size_t size);
void	*ft_memchr(const void *arr, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memset(void *buf, int ch, size_t count);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putnbr(int n);
void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_putnbr_fd(int n, int fd);

size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
size_t	ft_w_count(char const *s, char c);

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}						t_list;


t_list	*ft_lstlast(t_list *head);
t_list	*ft_lstnew(int value);

int		ft_lstsize(t_list *head);
void	printList(t_list *head);
void	ft_lstadd_front(t_list **stack, t_list *new);
void	ft_lstadd_back(t_list **stack, t_list *new);

#endif